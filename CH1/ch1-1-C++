# Problem 1.1: check if a string has all unique characters

//
//  main.cpp
//  Coding practice
//
//  Created by Tiantian Xu on 6/11/16.
//  Copyright © 2016 Tiantian Xu. All rights reserved.
//

#include <iostream>

bool isunique(char str[]) {
    
    bool dupe = true;
    bool checker[256] = {false};
    
    char cur_char = str[0];
    int pos = 0;
    
    while (cur_char != '\n'){
        if (checker[int(cur_char)]) {
            dupe = false;
            return dupe;
        }
        checker[int(cur_char)] = true;
        
        pos++;
        cur_char = str[pos];
        
    }
    
    
    return dupe;
}

int main(int argc, const char * argv[]) {
    
    char str[]={'a','b','c','d','\n'};
    
    if (isunique(str)) {
        std::cout << str << " contains all unique characters";
    }else
        std::cout << str << " contains duplicate characters";

    
    
    return 0;
}



