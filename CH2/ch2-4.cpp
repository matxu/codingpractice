// Partition a list around a value x, s.t. all nodes less than x come before all nodes greater than or equal to x.
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

void partitionList(ListNode *head, int x){
   //Loop over list and move node less than x to front
    if (head->next==NULL || head->next->next==NULL) return;
    
    ListNode *p=head, *second=head->next;
    
    while (p!=NULL && p->next!=NULL){
        if (p->next->val < x) {
            head->next=p->next;
            p->next=p->next->next;
            head->next->next=second;
            second=head->next;
        }else
            p=p->next;
    }
    
}

int main(int argc, const char * argv[]) {
   
    ListNode head=ListNode(-1);
 
    ListNode a=ListNode(4);
    ListNode b=ListNode(2);
    ListNode c=ListNode(3);
    ListNode d=ListNode(4);
    ListNode e=ListNode(1);
    
    
    head.next=&a;
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;

    cout<<"Original list is: "<<endl;
    printList(&head);
    int x=3;
    partitionList(&head,x);
    cout<<"After partition around " << x << ": "<<endl;
    printList(&head);
    return 0;
}

