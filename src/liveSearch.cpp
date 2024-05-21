//
// Created by vjgti on 5/21/2024.
//

#include "liveSearch.h"

#include <string>
#include <vector>

#include "terminalCommands.h"

//clear screen
//while true loop
//section to display what type of search is working. ie regular regex etc
//search
//list of valid files
    //can i scroll through these?
//amount of files returned
//recursive search?

void liveSearch(std::vector<fileInfoStruct> files, std::string command) {
    clearScreen();
    xy wd = detectSize();
    displayTime();
    displayDirBar(path_dir);

    sendData(std::string(wd.x, renderCodes.divHori), {0,1});
    std::string searchPattern = "regular";
    std::string searchString = "";
    if (!command.empty()) {
        std::vector<std::string> tokens = tokenizeInput(command);
        for(int i = 0; i < tokens.size(); ++i) {
            if(tokens[i] == "-t" && i+1 < tokens.size()) {
                searchPattern = tokens[i+1];
            }
            if(tokens[i] == "-s" && i+1 < tokens.size()) {
                searchString = tokens[i+1];
            }
        }
    }
    return;
}
