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
    int sumNumbers(TreeNode* root) {
        int total = 0;
        dfs(root, total, "");
        return total;
    }
    
    void dfs(TreeNode* node, int& total, string path){
        
        if (node -> left == nullptr && node -> right == nullptr) {
            total += stoi(path + to_string(node -> val));
        } else {
            if (node -> left != nullptr) {
                dfs(node -> left, total, path + to_string(node -> val));
            }
            if (node -> right != nullptr) {
                dfs(node -> right, total, path + to_string(node -> val));
            }
        }
        
    }
};