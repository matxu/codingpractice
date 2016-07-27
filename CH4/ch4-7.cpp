// find the lowest common ancestor of two nodes

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
     * @param root: The root of the binary search tree.
     * @param A and B: two nodes in a Binary.
     * @return: Return the least common ancestor(LCA) of the two nodes.
     */
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *A, TreeNode *B) {
        // write your code here
        
        if ( root == NULL || A == NULL || B == NULL) return NULL;
        if ( !isAncestor(root,A) || !isAncestor(root,B)) return NULL;
        
        // If A is the ancestor of B or B is the ancestor of A, return itself
        if (isAncestor(A,B)) return A;
        if (isAncestor(B,A)) return B;
        
        // Find the last node that is the ancestor of both A and B
        TreeNode *curnode = root;
        bool left1 = false, left2 = false, right1 = false, right2 = false;
        
        while ( true ) {
            left1 = isAncestor(curnode->left,A);
            left2 = isAncestor(curnode->left,B);
            if (left1 && left2) curnode = curnode->left;
            else if (left1 || left2 ) return curnode;
            else{
                right1 = isAncestor(curnode->right,A);
                right2 = isAncestor(curnode->right,B);
                if ( right1 && right2) curnode = curnode->right;
                else if (right1 || right2) return curnode;
            }
        }
        
        
    }
    
    // Returns true is root is an ancestor of p
    bool isAncestor(TreeNode *root, TreeNode *p) {
        if ( root == NULL ) return false;
        if ( root == p ) return true;
        
        bool leftPart = isAncestor(root->left, p);
        bool rightPart = isAncestor(root->right, p);
        
        if ( leftPart || rightPart) return true;
        else
            return false;

    }
    
};
