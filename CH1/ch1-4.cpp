// Problem 1.4: Replace spaces in a string with %20

//
//  main.cpp
//  Coding practice
//
//  Created by Tiantian Xu on 6/11/16.
//  Copyright © 2016 Tiantian Xu. All rights reserved.
//

#include <iostream>
using namespace std;

void replaceSpaces(char* str,int len) {
    int back=0, spcount=0;
    
    while (back < len-1) {
        if (str[back] == ' ') spcount++;
        back++;
    }
    
    int newback = back + spcount*2;
    char cur_char = ' ';
    while (back > 0) {
        cur_char = str[back];
        
        if (cur_char == ' ') {
            str[newback] = '0';
            str[newback-1] = '2';
            str[newback-2] = '%';
            
            newback -= 3;
        }else {
            str[newback] = str[back];
            newback--;
        }
        
        
        
        back--;
    }
    
    
}

int main(int argc, const char * argv[]) {
    
    char str[] = "Baked goods: croissants, muffins and quiche.            ";
    
    int len=44;
    replaceSpaces(str,len);
    
    cout << " After replacing spaces, string becomes: \n" << str << endl;
    
    return 0;
}

