//
//  replace.cpp
//  a4-code-html-safe
//
//  Created by Alexander Cochrane on 2016-11-07.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#include "contants.h"
#include "replace.hpp"

// goes through the entire string and replaces all instances
// of a "bad" character with it's "good" character
void Replacer::replaceAll(std::string & orig, const std::string & find, const std::string &rep) {
    
    size_t position = 0;
    while ((position = orig.find(find, position)) != std::string::npos) {
        orig.replace(position, find.length(), rep);
        position += rep.length();
    }
    
}

// calls replaceAll for every character in the constants::badChars
// and it's corresponding character in the constants::goodChars
void Replacer::htmlReplaceCharacters(std::string & in) {
    
    // starts the string with html pre and code things
    std::string temp = "<pre><code>";
    for (int i = 0; i < numChars; i++) {
        replaceAll(in, badChars[i], goodChars[i]);
    }
    temp.append(in);
    // ends the string with html pre and code things
    temp.append("</code></pre>");
    in = temp;
}
