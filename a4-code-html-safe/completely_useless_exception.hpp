//
//  completely_useless_exception.hpp
//  a4-code-html-safe
//
//  Created by Alexander Cochrane on 2016-11-17.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#ifndef completely_useless_exception_hpp
#define completely_useless_exception_hpp

#include <stdexcept>
#include <stdio.h>

// a custom exception, because apparently we need one

class completelyUselessException : public std::exception {
private:
    const char * msg;
public:
    completelyUselessException();
    completelyUselessException(const char * what);
    virtual const char* what() const throw();
};

#endif /* completely_useless_exception_hpp */
