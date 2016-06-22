// Given only access to the middle node, remove it

//
//  main.cpp
//  Coding practice
//
//  Created by Tiantian Xu on 6/11/16.
//  Copyright © 2016 Tiantian Xu. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

void printList(ListNode *head){
    int temp=0;
    while(head !=NULL && head->next !=NULL){
        temp=head->next->val;
        cout << temp <<endl;
        head=head->next;
    }
    
}

void deleteMid(ListNode *mid){
    // Move everything front
    while(mid->next !=NULL){ //could just do while true?
        mid->val=mid->next->val;
        if (mid->next->next == NULL){
            mid->next = NULL;
            return;
        }
        mid=mid->next;
    }
    
}

int main(int argc, const char * argv[]) {
   
    ListNode head=ListNode(-1);
 
    ListNode a=ListNode(1);
    ListNode b=ListNode(2);
    ListNode c=ListNode(3);
    ListNode d=ListNode(4);
    ListNode e=ListNode(5);
    
    
    head.next=&a;
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;

    cout<<"Original list is: "<<endl;
    printList(&head);
    deleteMid(&c);
    cout<<"After deleting mid node: "<<endl;
    printList(&head);
    return 0;
}

