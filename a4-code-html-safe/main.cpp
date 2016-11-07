//
//  main.cpp
//  a4-code-html-safe
//
//  Created by Alexander Cochrane on 2016-11-07.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include "replace.hpp"
#include "fileloader.hpp"

int main() {
    std::cout << "Enter filename to convert to HTML-friendly text: ";
    std::string filename;
    getline(std::cin,filename);
    std::cout << std::endl;
    std::cin.clear();
    
    if (!FileLoader::validateFilePath(filename, "windows")) {
        std::cout << "That is not a valid filename." << std::endl;
        return main();
    }
    
    std::string html = FileLoader::loadFileToString(filename);
    
    Replacer::htmlReplaceCharacters(html);
    
output_spot:
    
    std::cout << "Enter output filename: ";
    filename.clear();
    getline(std::cin,filename);
    std::cout << std::endl;
    std::cin.clear();
    
    if (!FileLoader::validateFilePath(filename, "windows")) {
        std::cout << "That is not a valid filename." << std::endl;
        goto output_spot;
    }
    
    return 0;
}
