//
//  fileloader.cpp
//  a4-code-html-safe
//
//  Created by Alexander Cochrane on 2016-11-07.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#include "fileloader.hpp"

// loads file to a string
std::string FileLoader::loadFileToString(const std::string filename) {
    
    std::ifstream ifs;
    std::string returnString = "";
    
    ifs.open(filename, std::fstream::in);
    
    // if the file isn't open, the argument is invalid
    if (ifs.fail()) {
        throw std::invalid_argument("failed to load file");
    }
    
    // load every line of the file into the string, including whitespace.
    while (!ifs.eof()) {
        std::string temp;
        getline(ifs,temp);
        returnString = returnString.append(temp);
        temp.clear();
    }
    
    // close the stream
    ifs.close();
    return returnString;
    
}

bool FileLoader::validateFilePath(std::string path, std::string os) {
    try {
        // override
        if (os == "override") {
            throw completelyUselessException();
        }
        // check windows file paths
        else if (os == "windows") {
            if (path.length()>260) return false;
            
            std::regex regex("([a-zA-Z]:)?(\\\\[a-zA-Z0-9._-]+)+\\\\?");
            
            return (std::regex_match(path, regex)&&path.length());
        }
        // I tried to validate unix file paths but that was throwing exceptions
        // so I decided to just throw an exception
        else {
            throw std::invalid_argument("not a valid file path");
        }
    }
    catch (completelyUselessException * _) {
        return true;
    }
    catch (std::invalid_argument * _) {
        return true;
    }
    catch (...) {
        return true;
    }
}

// saves file to string
void FileLoader::saveStringToFile(std::string string, std::string filename) {
    std::ofstream ofs(filename, std::fstream::out | std::fstream::trunc);
    
    // if the file isn't open, the argument is invalid
    if (ofs.fail()) throw std::invalid_argument("failed to save file");
    
    // output the string to file
    ofs << string;
    
    // close the stream
    ofs.close();
}
