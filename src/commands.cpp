//
// Created by vjgti on 5/3/2024.
//

#include "commands.h"

#include <cstring>
#include <string>
#include <iostream>
#include <sys/stat.h>
#include <direct.h>
#include <stdlib.h>
#include <stdio.h>

#include <fstream>

#include "keyTracker.h"
#include "miscFunctions.h"
#include "configInfo.h"
#include "terminalCommands.h"




//display an error message under cmd line
void displayError(const std::string &message) {
    xy wd = detectSize();
    sendData(message, {0, wd.y-1});
}


//update dir on user input through :cd <dir>
void changeDir(const std::string &command) {
    std::string subCommand = command.substr(command.find(' ') + 1);
    struct stat sb;
    std::string temp = path_dir;
    if (subCommand[1] == ':') {
        if (subCommand.back() != '\\') {
            subCommand += '\\';
        }
        path_dir = subCommand;

    } else if (subCommand.substr(0, 2) == "..") {
        char full[_MAX_PATH];
        if (_fullpath(full, (path_dir + "\\" + subCommand).c_str(), _MAX_PATH) != NULL) {
            path_dir = full;
            path_dir += '\\';
        } else {
            displayError("Change Dir Failed");
        }

    } else {
        path_dir = path_dir + "\\" + subCommand + "\\";
    }

    if (stat(path_dir.c_str(), &sb) != 0) {
        displayError("Invalid directory");
        path_dir = temp;
        return;
    }

    changeDir(fileInformation, path_dir);
}

//display help page for provided command - q to quit
void displayHelp(const std::string &command) {
    std::string subCommand = command.substr(command.find(' ') + 1);
    debugOutput(subCommand + " aouthn", -14);
    std::ifstream openFile("./helpInfo/" + subCommand + ".txt");
    if (openFile.is_open()) {
        debugOutput(subCommand + " 11111", -14);
        std::string fileData;
        clearScreen();
        // setCursorPosition(0, 0);
        sendData("Command: " + command.substr(command.find(' ')) + "\n", {0,0});
        while (openFile) {
            fileData = openFile.get();
            sendData(fileData);
        }
        sendData("Press 'q' to quit");
    } else {
        displayError("Command does not exist or no help file");
        return;
    }
    while (true) {
        const int key = key_press();
        if (key == 'q') {
            maintainStateRefresh(fileInformation);
            break;
        }
    }
}


void launchNVim(const std::string& command) {
    if (command.length() == 4) {
        if (fileInformation[fileSelectionPointer].extention != "<DIR>") {
            system(("nvim " + path_dir + "\\" + fileInformation[fileSelectionPointer].name).c_str());
        }
        else {system("nvim");}
     }
    else {
        std::string fileName = command.substr(command.find(' ')+1);
        system(("nvim " + path_dir + "\\" + fileName).c_str());
    }
    ShowScrollBar(GetConsoleWindow(), SB_VERT, 0);
    toggleVT(true);
    maintainStateRefresh(fileInformation);
}

void refreshConfig() {
    readUserConfig();
    maintainStateRefresh(fileInformation);
}

void createDir(std::string& command) {
    if (_mkdir(      (path_dir +"\\" +command.substr(command.find(' ') +1)).c_str()       ) == 0) {
    } else {
        displayError("Error Creating folder: " + command.substr(command.find(' ') +1));
    }
    researchDir();
    return;
}

void createFile(std::string& command) {  //TODO: implement spaced name and error
    std::string Fname;
    if (command.substr(command.find(' ') +1,1) != "\"") {
        Fname = command.substr(command.find(' ') +1);
    }
    std::string path = path_dir + '\\' + Fname;
    HANDLE h = CreateFileA(path.c_str(),    // name of the file
                      GENERIC_WRITE, // open for writing
                      0,             // sharing mode, none in this case
                      nullptr,             // use default security descriptor
                      CREATE_NEW, // dont overwrite if exists - could add option
                      FILE_ATTRIBUTE_NORMAL,
                      nullptr);

    if (h) {
        CloseHandle(h);
    } else { //TODO: doesnt work
        displayError(std::to_string(GetLastError()));
    }
    researchDir();
    return;
}