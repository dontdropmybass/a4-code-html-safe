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
    std::string os;
    getline(std::cin,os);
    std::cin.clear();
    std::cout << std::endl;
    std::cout << "Enter fully qualified file path to convert to HTML-friendly text: ";
    std::string filename;
    getline(std::cin,filename);
    std::cout << std::endl;
    std::cin.clear();
    
    if (!FileLoader::validateFilePath(filename, os)) {
        std::cout << "That is not a valid filename." << std::endl;
        return main();
    }
    
    std::string html = FileLoader::loadFileToString(filename);
    
    Replacer::htmlReplaceCharacters(html);
    
output_spot:
    
    std::cout << "Enter fully-qualified path for output: ";
    filename.clear();
    getline(std::cin,filename);
    std::cout << std::endl;
    std::cin.clear();
    
    if (!FileLoader::validateFilePath(filename, "windows")) {
        std::cout << "That is not a valid filename." << std::endl;
        goto output_spot;
    }
    
    FileLoader::saveStringToFile(html, filename);
    
    _getch();
    
    return 0;
}
