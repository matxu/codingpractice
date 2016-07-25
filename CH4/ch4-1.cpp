// Implement a function to check if a tree is balanced

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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        int depth = -1;
        return isBalancedHelper(root, depth);
    }
    
    bool isBalancedHelper(TreeNode *root, int &depth) {
        if ( root == NULL) {
            depth = 0;
            return true;
        }
        if (root->left == NULL){
            if (root->right == NULL){
                depth = 1;
                return true;
            }
            else {
                int rightdepth = -1;
                bool rightBalanced = isBalancedHelper(root->right, rightdepth);
                depth = rightdepth + 1;
                if ( rightdepth > 1 ){
                    return false;
                }else
                    return true;
            }
                
        }else if ( root->right == NULL ){
            int leftdepth = -1;
            bool leftBalanced = isBalancedHelper(root->left, leftdepth);
                depth = leftdepth + 1;
                if ( leftdepth > 1 ){
                    return false;
                }else
                    return true;
        }else {
            int rightdepth = -1;
            bool rightBalanced = isBalancedHelper(root->right, rightdepth);
            int leftdepth = -1;
            bool leftBalanced = isBalancedHelper(root->left, leftdepth);
            
            bool childrenBalanced = false, isbal = false; 
            if ( (leftdepth-rightdepth <= 1) || (leftdepth-rightdepth >= -1))
                childrenBalanced = true;     
            else
                childrenBalanced = false;
            
            if (rightBalanced && leftBalanced && childrenBalanced)
                isbal = true;
            else
                isbal = false;
                
            if ( leftdepth > rightdepth)
                depth = leftdepth+1;
            else
                depth = rightdepth+1;
            
            return isbal;
            
            
        }
        
        
    }

};
