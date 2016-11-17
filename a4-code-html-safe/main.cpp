//
//  main.cpp
//  a4-code-html-safe
//
//  Created by Alexander Cochrane on 2016-11-07.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#define _getch() std::system("read -n1 -p 'Press any key...\n' key");
#define _cls()   std::cout << string(50, '\n');

#include <iostream>
#include <stdio.h>
#include "replace.hpp"
#include "fileloader.hpp"

int main() {
    std::cout << "Enter the operating system you are running this on: ";
    // take os for file path validation
    std::string os;
    getline(std::cin,os);
    std::cin.clear();
    std::cout << std::endl;
    // get original filename from user
    std::cout << "Enter fully qualified file path to convert to HTML-friendly text: ";
    std::string filename;
    getline(std::cin,filename);
    std::cout << std::endl;
    std::cin.clear();
    
    // check if file path is valid
    if (!FileLoader::validateFilePath(filename, os)) {
        std::cout << "That is not a valid filename." << std::endl;
        // if it isn't valid, return to the beginning.
        return main();
    }
    
    std::string html;
    
    // try to load the file
    try {
        html = FileLoader::loadFileToString(filename);
    }
    
    catch (...) {
        std::cout << "That is not a valid filename." << std::endl;
        // if that doesn't work, return to the beginning
        return main();
    }
    
    Replacer::htmlReplaceCharacters(html);
    
output_spot: // label to return to later
    
    std::cout << "Enter fully-qualified path for output: ";
    filename.clear();
    // get the output filename
    getline(std::cin,filename);
    std::cout << std::endl;
    std::cin.clear();
    
    if (!FileLoader::validateFilePath(filename, os)) {
        std::cout << "That is not a valid filename." << std::endl;
        // if that's not valid, go back to the label
        goto output_spot;
    }
    
    // try to save the file
    try {
        FileLoader::saveStringToFile(html, filename);
    }
    
    catch (...) {
        std::cout << "That is not a valid filename." << std::endl;
        // if that doesn't work, go back to the label
        goto output_spot;
    }
    
    _getch();
    
    return 0;
}
