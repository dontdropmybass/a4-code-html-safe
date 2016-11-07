//
//  fileloader.cpp
//  a4-code-html-safe
//
//  Created by Alexander Cochrane on 2016-11-07.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#include "fileloader.hpp"

std::string FileLoader::loadFileToString(const std::string filename) {
    
    std::ifstream ifs;
    std::string returnString;
    
    ifs.open(filename, std::fstream::in);
    
    if (!ifs.is_open()) {
        return "failed to load file";
    }
    
    while (!ifs.eof()) {
        ifs >> returnString;
    }
    
    ifs.close();
    return returnString;
    
}

bool FileLoader::validateFilePath(std::string path, std::string filesystem) {
    return true;/// TODO replace
}

void FileLoader::saveStringToFile(std::string string, std::string filename) {
    
    std::fstream fs;
    
    fs.open(filename, std::fstream::out | std::fstream::trunc);
    if (!fs.is_open()) std::cout << "File does not exist." << std::endl;
    fs << string;
    fs.close();
}
