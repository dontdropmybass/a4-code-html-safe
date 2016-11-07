//
//  replace.hpp
//  a4-code-html-safe
//
//  Created by Alexander Cochrane on 2016-11-07.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#ifndef replace_hpp
#define replace_hpp

#include <string>
#include <stdio.h>

class Replacer {
    
public:
    
    static void replaceAll(std::string & orig, const std::string & find, const std::string & rep);
    
    static void htmlReplaceCharacters(std::string & in);
    
};

#endif /* replace_hpp */
