// Problem 1.5: Compress string, ie., aabbccc -> a2b2c3. Return original string if compressed is longer.

//
//  main.cpp
//  Coding practice
//
//  Created by Tiantian Xu on 6/11/16.
//  Copyright © 2016 Tiantian Xu. All rights reserved.
//

#include <iostream>
using namespace std;

void compressString(char str[],char* rstr) {
    
    if (str[0] == '\0' || str[1] == '\0') return;
    int pos=0, back=1;
    
    bool done=false;
    char cur_char=' ';
    int counter=0, pos2=0;
    
    while (!done) {
        cur_char = str[pos];
        counter=1;
        while (str[back] == cur_char) {
            back++;
            counter++;
        }
        rstr[pos2]=cur_char;
        rstr[pos2+1]=char(counter+'0');
        pos2 +=2;
        
        if (str[back] == '\0') done=true;
        else {
            pos=back;
            back++;
        }
    }
    
    rstr[pos2]='\0';
    
    if (pos2>back-1) { // compressed string is longer than original
        while (back>0) {
            rstr[back]=str[back];
            back--;
        }
    }
}


int main(int argc, const char * argv[]) {
    
    char str[] = "abbaaacccddd";
    char str2[] = "abbaaacccddd";
    
    compressString(str,str2);
    
    cout << " Compressed string is " << str2 << endl;
    
    
    return 0;
}

