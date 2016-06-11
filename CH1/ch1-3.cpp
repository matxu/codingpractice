// Problem 1.3: check if one string is the permutation of another string

//
//  main.cpp
//  Coding practice
//
//  Created by Tiantian Xu on 6/11/16.
//  Copyright © 2016 Tiantian Xu. All rights reserved.
//

#include <iostream>
using namespace std;

bool ispermute(char str1[], char str2[]) {
    
    bool answer = true;
    int len1 = 0, len2 = 0;
    
    while (str1[len1] != '\0') len1++;
    while (str2[len2] != '\0') len2++;
    if (len1 != len2) {
        answer = false;
        return answer;
    }
    
    int count[256] = {0};
    
    for (int i=0; i<len1; i++)
        count[int(str1[i])]++;
    
    for (int i=0; i<len2; i++) {
        count[int(str2[i])]--;
        if (count[int(str2[i])] < 0) {
            answer=false;
            return answer;
        }
    }

    return answer;
}

int main(int argc, const char * argv[]) {
    
    char str1[] = "abcddefgg";
    char str2[] = "ffgabcdde";
    
    if (ispermute(str1,str2))
        cout << str1 << " is a permutation of " << str2 << endl;
    else
        cout << str1 << " is NOT a permutation of " << str2 << endl;
    
    return 0;
}

