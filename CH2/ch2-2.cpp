// Find the kth to last element

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

int kthElement(ListNode *head,int k){
    if (head==NULL) return NULL;
    
    if (head->next->next == NULL) {
        if (k>1) return NULL;
        else return head->next->val;
    }
    
    //Find kth to last element
    ListNode *slow=head, *fast=head;
    
    // First, move fast k steps
    int counter=0;
    while (counter<k) {
        counter++;
        fast=fast->next;
        if (fast==NULL) return NULL; // Length of list less than k
    }
    
    while (fast->next != NULL) {
        fast=fast->next;
        slow=slow->next;
    }
    return slow->val;
    
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
    int k=6;
    int val=kthElement(&head,k);
    if (val==NULL)
        cout<<"Wrong input"<<endl;
    else
        cout<<"The " << k << " th element to last is "<<val<<endl;
    return 0;
}

