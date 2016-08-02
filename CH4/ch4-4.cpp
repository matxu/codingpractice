//
//  main.cpp
//  Coding practice
//
//  Created by Tiantian Xu on 6/11/16.
//  Copyright © 2016 Tiantian Xu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void printList(ListNode *head){
    int temp=0;
    while(head !=NULL && head->next !=NULL){
        temp=head->next->val;
        cout << temp <<endl;
        head=head->next;
    }
    
}

vector<ListNode*> treeLevel(TreeNode *root){
    
    vector<ListNode*> result;
    ListNode* temp;

    if ( root == nullptr) return result;
    if ( root->right == nullptr && root->left == nullptr ) {
        temp = new ListNode(root->val);
        result.push_back(temp);
        return result;
    }
    
    
    queue<TreeNode*> q1, q2;
    
    q1.push(root);
    temp = new ListNode(-1);
    result.push_back(temp);
    
    int level = 0;
    
    ListNode *p;
    
    TreeNode* curnode;
    while ( !q1.empty() ) {
        
        
        curnode = q1.front();
        q1.pop();
        temp = new ListNode(curnode->val);
        
        // add curnode to list
        p = result[level];
        while(p->next!=NULL) p=p->next;
        p->next = temp;
        
        if ( curnode->right != nullptr ) q2.push(curnode->right);
        if ( curnode->left != nullptr) q2.push(curnode->left);
        
        // shuffle q1,q2, add level and make new dummy head for new level
        if ( q1.empty() && !q2.empty()) {
            while ( !q2.empty()){
               curnode = q2.front();
               q2.pop();
               q1.push(curnode);
            }
            level++;
            temp = new ListNode(-1);
            result.push_back(temp);
        }
        
    }
    
    
    return result;
}


int main(int argc, const char * argv[]) {
    
    TreeNode* root = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(4);
    TreeNode* d = new TreeNode(5);
    TreeNode* e = new TreeNode(6);
    TreeNode* f = new TreeNode(7);
    
    root->left = a; root->right = b;
    a->left = c; a->right = d;
    c->left = e;
    d->right = f;
    
    vector<ListNode*> result = treeLevel(root);
    int level = result.size();
    for (int i=0; i< level; i++) {
        cout<< "Level "<< i << endl;
       printList(result[i]);
    }
    

   
    return 0;
}

