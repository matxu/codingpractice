// Problem 1.2: Reverse a string in place

//
//  main.cpp
//  Coding practice
//
//  Created by Tiantian Xu on 6/11/16.
//  Copyright © 2016 Tiantian Xu. All rights reserved.
//

#include <iostream>
using namespace std;

void reverse(char* str) {
    // two points
    
    if (str[0]=='\0' || str[1] == '\0') return;
    
    int front = 0, back = 0;
    
    while (str[back]!='\0') back++;
    back--;
    
    char temp = ' ';
    
    while (front < back) {
        temp = str[front];
        str[front] = str[back];
        str[back] = temp;
        front++;
        back--;
    }
    
    
    
    
}

int main(int argc, const char * argv[]) {
    
    char str[]="abcddeffg";
    
    reverse(str);
    
    cout << "After reverse: " << str;
    
    
    return 0;
}



