/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int previous = pow(10, 6);
    int minDist = pow(10, 6);
    
    void inOrderTraversal(TreeNode* node){
        
        if (node == nullptr) {
            return;
        }
        
        inOrderTraversal(node -> left);
        minDist = min(abs(node -> val - previous), minDist);
        previous = node -> val;
        inOrderTraversal(node -> right);
            
    }
    
    int minDiffInBST(TreeNode* root) {
        inOrderTraversal(root);
        return minDist;
    }
};