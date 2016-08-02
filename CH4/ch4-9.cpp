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

void checkPath(vector<int> path, int target) {
    // looking from path[-1]to path[0]
    int len = path.size();
    int cursum = 0;
    for ( int i=len-1; i>=0; i--){
        cursum += path[i];
        if ( cursum == target ){
            for ( int j = i; j<len; j++)
                cout << path[j] << " ";
            cout<<endl;
        }
    }
}

void allpath(TreeNode *root, vector<int>& path, int target){
    if ( root == nullptr) return;
    
    // starting condition
    if ( path.empty() ) {
        path.push_back(root->val);
        if ( root-> val == target)
            cout << root->val << endl;
    }
    
    if ( root->left != nullptr) {
       path.push_back(root->left->val);
        checkPath(path, target);
        allpath(root->left,path,target);
        path.erase(path.end()-1);
    }
    
    if ( root->right != nullptr) {
        path.push_back(root->right->val);
        checkPath(path, target);
        allpath(root->right,path,target);
        path.erase(path.end()-1);
    }
    
}


int main(int argc, const char * argv[]) {
    
    TreeNode* root = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(-3);
    TreeNode* d = new TreeNode(-7);
    TreeNode* e = new TreeNode(6);
    TreeNode* f = new TreeNode(7);
    
    root->left = a; root->right = b;
    a->left = c; a->right = d;
    c->left = e;
    d->right = f;
    
    vector<int> path;
    int target = 3;
    
    allpath(root,path,target);

   
    return 0;
}

