// Remove duplicates from a linkedlist 

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

int removeDup(ListNode *head){
    
    if (head->next == NULL || head->next->next == NULL) return 0;
    
    ListNode *p;
    p=head->next;
    
    //check if the first val exists in second to last
    //check if the second val exists in third to last
    
    ListNode *slow=head->next;
    while (slow!=NULL && slow->next!=NULL){
        p=slow; // look at p->next-val with slow->val
        while(p!=NULL && p->next !=NULL){
            if (p->next->val == slow->val) //dup, remove p->next
                p->next=p->next->next;
            else p=p->next;
        }
        
        
        slow=slow->next;
    }
    
    
    return 0;
}

int main(int argc, const char * argv[]) {
   
    ListNode head=ListNode(-1);
 
    ListNode a=ListNode(1);
    ListNode b=ListNode(1);
    ListNode c=ListNode(1);
    ListNode d=ListNode(1);
    ListNode e=ListNode(2);
    
    
    head.next=&a;
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=&e;

    cout<<"Original list is: "<<endl;
    printList(&head);
    
    removeDup(&head);
    
    cout<<"After removing duplicates, new list is"<<endl;
    printList(&head);
    return 0;
}

