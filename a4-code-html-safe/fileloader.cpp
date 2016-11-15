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
    std::string returnString = "";
    
    ifs.open(filename, std::fstream::in);
    
    if (!ifs.is_open()) {
        return "failed to load file";
    }
    
    while (!ifs.eof()) {
        std::string temp;
        getline(ifs,temp);
        returnString = returnString.append(temp);
        temp.clear();
    }
    
    ifs.close();
    return returnString;
    
}

bool FileLoader::validateFilePath(std::string path, std::string os) {
    try {
        if (os == "override") {
            return true;
        }
        else if (os == "windows") {
            if (path.length()>260) return false;
            
            std::regex regex("([a-zA-Z]:)?(\\\\[a-zA-Z0-9._-]+)+\\\\?");
            
            return (std::regex_match(path, regex)&&path.length());
        }
        else {
            std::regex regex("[^\0]+");
            return std::regex_match(path, regex);
        }
    }
    catch (...) {
        return true;
    }
}

std::vector<std::string> FileLoader::split(const std::string &s, char delim) {
    std::stringstream stream(s);
    std::string item;
    std::vector<std::string> tokens;
    while (getline(stream, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

void FileLoader::saveStringToFile(std::string string, std::string filename) {
    std::ofstream ofs(filename, std::fstream::out | std::fstream::trunc);
    ofs << string;
    ofs.close();
}
