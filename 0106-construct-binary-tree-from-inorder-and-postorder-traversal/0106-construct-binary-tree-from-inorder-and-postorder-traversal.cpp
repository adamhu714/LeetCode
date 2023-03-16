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
    
        
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        for (int i = 0; i < inorder.size(); ++i) {
            ump[inorder[i]] = i;           
        }
        int rootidx = inorder.size() - 1;
        return build(inorder, postorder, 0, inorder.size() - 1, rootidx);
    }

private:
    
    unordered_map<int, int> ump;
    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int left, int right, int& rootidx) {
        if (left > right) return nullptr;
        TreeNode *node = new TreeNode(postorder[rootidx--]);
        node -> right = build(inorder, postorder, ump[node -> val] + 1, right, rootidx);
        node -> left = build(inorder, postorder, left, ump[node -> val] - 1, rootidx);
        return node;
    }
    
};