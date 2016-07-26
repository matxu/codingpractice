// Implement a function to return the in order successor of a node

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        // write your code here
        if ( root == NULL || p == NULL ) return NULL;
        
        if ( root == p && root -> left == NULL && root -> right == NULL) return NULL;
        
        // if p has right child, successor is the leftest node in p's sub tree
        if ( p -> right != NULL )  { 
            p = p->right;
            while ( p -> left != NULL) {
            p = p->left;
            }
            return p;
        }
        TreeNode* parent = findNodeParent(root,p);
        
        // if p does not have right childe & p is parent's left child, successor is p's parent
        if ( parent -> left == p ) return parent;
        
        // if p does not have right child & p is parent's right child & p's parent is some node's left child, successor is that node        
        // if p does not have right child & p's parent is no node's left child, p's successor is null 

        TreeNode* smallAncestor = findSmallAncestor(root, p);
        return smallAncestor;

    }

    TreeNode* findNodeParent(TreeNode* root, TreeNode* p){
        if ( root == p ) return nullptr;
        TreeNode* curnode = root, *parent;
        while ( curnode != NULL){
            if ( curnode -> val > p->val ){
                if ( curnode -> left == p ) {
                    parent = curnode;
                    return parent;
                }else 
                    curnode = curnode -> left;
            }else {
                if ( curnode -> right == p ){
                    parent = curnode;
                    return parent;
                }else
                    curnode = curnode -> right;
            }
        }
        
        return nullptr; // not found
    }
    
    TreeNode* findSmallAncestor(TreeNode* root, TreeNode* p){
        TreeNode* sa = NULL;
        TreeNode* curnode = root;
        
        while ( curnode != NULL ){
            if ( curnode -> val > p->val ){
                sa = curnode; // sa is larger than p
                if ( curnode -> left == p ) {
                    return sa;
                }else 
                    curnode = curnode -> left;
            }else {
               
                if ( curnode -> right == p ){
                    return sa;
                }else
                    curnode = curnode -> right;
            }
        }
        
        return sa;
    }
    
};
