// Problem 1.7: If an entry in a matrix is 0, set the row and col to 0s

//
//  main.cpp
//  Coding practice
//
//  Created by Tiantian Xu on 6/11/16.
//  Copyright © 2016 Tiantian Xu. All rights reserved.
//

#include <iostream>
using namespace std;

void makezeros(int arr[][5],int M, int N) {
    
    bool *rows = new bool(M);
    for (int i=0;i<M;i++) rows[i]=false;
    
    bool *cols = new bool(N);
    for (int i=0;i<N;i++) cols[i]=false;
    
    for (int i=0; i<M; i++)
        for(int j=0;j<N; j++){
            if (arr[i][j]==0) {
                rows[i]=true;
                cols[j]=true;
            }
        }
    
    for (int i=0;i<M;i++)
        for (int j=0; j<N; j++) {
            if (rows[i] || cols[j])
                arr[i][j]=0;
        }
}

int main(int argc, const char * argv[]) {
    int arr[][5] = {{1,2,3,0,5},{6,7,8,9,10},{11,12,13,14,15},{0,17,18,19,20},{21,22,23,24,25}};
    int N = 5;
    
    cout<<"Originally the array is\n";
    
    for (int i=0;i<N;i++) {
        
        for(int j=0;j<N;j++)
            cout<<arr[i][j]<< " ";
        cout<<endl;
    }
    
    makezeros(arr,N,N); // arr is not necessarily square
    
    cout<<"After rotation the array is\n";
    
    for (int i=0;i<N;i++) {
        
        for(int j=0;j<N;j++)
            cout<<arr[i][j]<< " ";
        cout<<endl;
    }
    return 0;
}

