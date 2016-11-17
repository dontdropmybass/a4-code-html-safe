//
//  contants.h
//  a4-code-html-safe
//
//  Created by Alexander Cochrane on 2016-11-07.
//  Copyright © 2016 Alexander Cochrane. All rights reserved.
//

#ifndef contants_h
#define contants_h

#include <string>

// number of characters in both arrays
static const int numChars = 44;

// "unsafe" characters
static const std::string badChars[] = {
    "<",
    ">",
    "@",
    "[",
    "]",
    "`",
    "{",
    "|",
    "}",
    "~",
    "…",
    "†",
    "‡",
    "‘",
    "’",
    "“",
    "”",
    "•",
    "–",
    "—",
    "™",
    "¡",
    "¢",
    "£",
    "¥",
    "¦",
    "©",
    "«",
    "¬",
    "®",
    "°",
    "±",
    "²",
    "³",
    "¹",
    "»",
    "¼",
    "½",
    "¾",
    "¿",
    "÷",
    "“",
    "”",
    "—"
};

// safe characters to replace the bad "unsafe" characters
static const std::string goodChars[] = {
    "&#060;",
    "&#062;",
    "&#064;",
    "&#091;",
    "&#093;",
    "&#096;",
    "&#123;",
    "&#124;",
    "&#125;",
    "&#126;",
    "&#133;",
    "&#134;",
    "&#135;",
    "&#145;",
    "&#146;",
    "&#147;",
    "&#148;",
    "&#149;",
    "&#150;",
    "&#151;",
    "&#153;",
    "&#161;",
    "&#162;",
    "&#163;",
    "&#165;",
    "&#166;",
    "&#169;",
    "&#171;",
    "&#172;",
    "&#174;",
    "&#176;",
    "&#177;",
    "&#178;",
    "&#179;",
    "&#185;",
    "&#187;",
    "&#188;",
    "&#189;",
    "&#190;",
    "&#191;",
    "&#247;",
    "&#8220;",
    "&#8221;",
    "&#8212;"
};

#endif /* contants_h */
