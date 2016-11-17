//
//  completely_useless_exception.cpp
//  a4-code-html-safe
//
//  Created by Alexander Cochrane on 2016-11-17.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#include "completely_useless_exception.hpp"

// MY CODE IS SELF DOCUMENTING
//  -Everybody who codes
//    -Michael Scott

completelyUselessException::completelyUselessException(const char * what) : msg(what) {}
completelyUselessException::completelyUselessException()
    : msg("No error, I just had to throw this for fun.") {}

const char * completelyUselessException::what() const throw() {
    return this->msg;
}
