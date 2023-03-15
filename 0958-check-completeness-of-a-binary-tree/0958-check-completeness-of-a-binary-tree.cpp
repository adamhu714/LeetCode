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
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*> nodes;
        
        nodes.push(root);
        TreeNode* node = nullptr;
        bool nullfound = false;
        while(!nodes.empty()) {
            node = nodes.front();
            nodes.pop();
            if (node == nullptr) {
                nullfound = true;
            } else {
                if (nullfound == true) {
                    return false;
                }
                nodes.push(node -> left);
                nodes.push(node -> right);
            }
        }
        return true;
    }
};