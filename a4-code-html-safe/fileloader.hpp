//
//  fileloader.hpp
//  a4-code-html-safe
//
//  Created by Alexander Cochrane on 2016-11-07.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#ifndef fileloader_hpp
#define fileloader_hpp

#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <stdio.h>

class FileLoader {
    
public:
    
    static std::string loadFileToString(std::string filename);
    
    static void saveStringToFile(std::string string, std::string filename);
    
    static bool validateFilePath(std::string path, std::string os);
    
};

#endif /* fileloader_hpp */
