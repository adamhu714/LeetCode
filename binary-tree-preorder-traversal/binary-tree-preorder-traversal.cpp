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
    vector<int> pOT(TreeNode* root, vector<int> &ans) {
        if (root != nullptr) {
            ans.push_back(root -> val);
            pOT(root -> left, ans);
            pOT(root -> right, ans);
        }
        return ans;
        
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        ans = pOT(root, ans);
        return ans;
    }
};