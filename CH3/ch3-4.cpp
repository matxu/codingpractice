// Tower of Hanoi

//
//  main.cpp
//  Coding practice
//
//  Created by Tiantian Xu on 6/11/16.
//  Copyright © 2016 Tiantian Xu. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Stack{
public:

    Stack() {size=0;}

    int pop(){
        if ( size == 0 ) return NULL;
        int val = top->val;
        top = top->next;
        size--;
        return val;
        
    }
    
    void push(int val){
        if ( size == 0 ){
            top = new ListNode(val);
        }else {
            ListNode *temp = new ListNode(val);
            temp->next = top;
            top = temp;
        }
        size++;
    }
    
    int peek(){
        if ( size == 0 ) return NULL;
        int val = top->val;
        return val;
    }
    
private:
    ListNode *top;
    int size;
};

void towerOfHanoi(Stack* start, Stack* target, Stack* buffer, int n){
   // move n disks from start to target
    if ( n==1 ){
        int top = start->pop();
        target->push(top);
        return;
    }
    towerOfHanoi(start,buffer,target,n-1);
    int top = start->pop();
    target->push(top);
    towerOfHanoi(buffer,target,start,n-1);

}

int main(int argc, const char * argv[]) {
    
    vector<int> vals={5,4,3,2,1};
    
    Stack s1, s2, s3;
    int n = vals.size();
    for( int i = 0;i<n; i++)
        s1.push(vals[i]);
    
    towerOfHanoi(&s1,&s3,&s2,n);
  

   
    return 0;
}

