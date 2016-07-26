// Check if a binary tree is a binary search tree

/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        // write your code here
        
        if(root == NULL || &root == NULL) return true;
        
        if(root->left == NULL && root->right == NULL) return true;
        
        bool bl = true, br = true;
        
        if(root->left != NULL){
            if (root-> val <= root->left->val) return false;
            bl = isValidBST(root->left);
            if (!bl) return false;
            
            int lTrN = righty(root->left);
            if (root->val <= lTrN) return false;
        }
        
        if(root->right != NULL){
            if (root-> val >= root->right->val) return false;
            br = isValidBST(root->right);
            if (!br) return false;
            
            int rTlN = lefty(root->right);
            if (root->val >= rTlN) return false;
        }
        
        return true;
        
    }
    
    int lefty(TreeNode *root){
        // return the leftest node's value in tree root
        if(root == NULL || &root == NULL) return NULL;    
        
        while(root->left != NULL)
           root = root->left;
           
        return root->val;
    
    }
    
    int righty(TreeNode *root){
        // return the rightest node's value in tree root
        if(root == NULL || &root == NULL) return NULL;    
        
        while(root->right != NULL)
           root = root->right;
           
        return root->val;
    
    }
    
};
