// Problem 1.6: Rotate a NxN matrix by 90 degrees in place
// The following code rotates clockwise

//
//  main.cpp
//  Coding practice
//
//  Created by Tiantian Xu on 6/11/16.
//  Copyright © 2016 Tiantian Xu. All rights reserved.
//

#include <iostream>
using namespace std;

void rotateImage(int arr[][5], int N) {
    int left,right;
    int temp;
    for (int i=0;i<N/2;i++){
        left=i;
        right=N-i-1;
        
        for (int j=0; j<right-left; j++){
            temp=arr[left][left+j];
            arr[left][left+j]=arr[right-j][left];
            arr[right-j][left]=arr[right][right-j];
            arr[right][right-j]=arr[left+j][right];
            arr[left+j][right]=temp;
            
         }
        
    }
}

int main(int argc, const char * argv[]) {
    int arr[][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int N = 5;
    
    cout<<"Originally the array is\n";
    
    for (int i=0;i<N;i++) {
        
        for(int j=0;j<N;j++)
            cout<<arr[i][j]<< " ";
        cout<<endl;
    }
    
    rotateImage(arr,N);
    
    cout<<"After rotation the array is\n";
    
    for (int i=0;i<N;i++) {
        
        for(int j=0;j<N;j++)
            cout<<arr[i][j]<< " ";
        cout<<endl;
    }
    return 0;
}

