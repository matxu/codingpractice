// Convert sorted array to binary search tree with minimal height

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
     * @param A: A sorted (increasing order) array
     * @return: A tree node
     */
    TreeNode *sortedArrayToBST(vector<int> &A) {
        // write your code here
        int len = A.size();
        if ( len == 0 ) return nullptr;
        TreeNode *root = sortedArrayToBSThelper(A,0,len-1);
        return root;
    }
    
    TreeNode *sortedArrayToBSThelper(vector<int> &A, int left, int right){
        if ( left > right) return nullptr;
        int mid = getMedian(left,right);
        
        TreeNode *root = new TreeNode(A[mid]);
        if ( left == right ) return root;
        
        TreeNode *leftSubTree = sortedArrayToBSThelper(A, left, mid-1);
        TreeNode *rightSubTree = sortedArrayToBSThelper(A, mid+1, right);
        
        root -> left = leftSubTree;
        root -> right = rightSubTree;
        
        return root;
    }
    
    int getMedian(int left, int right){
        int mid = left + ( right - left )/2;
        return mid;
    }
};


