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

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> answer;
        vector<int> currentArr;
        TreeNode* current = 0;
        deque<TreeNode*> nodes;
        int counter = 1;
        nodes.push_back(root);
        int s;
        while (nodes.size()) {
            s = nodes.size();
            switch(counter%2) {
                case 0:
                    for (auto i = 0; i < s; ++i) {
                        current = nodes.back();
                        currentArr.push_back(current -> val);
                        if (current -> right != nullptr) {                    
                            nodes.push_front(current -> right);
                        }
                        if (current -> left != nullptr) {                    
                            nodes.push_front(current -> left);
                        }
                        nodes.pop_back();
                    }
                    break;
                    
                case 1:
                    for (auto i = 0; i < s; ++i) {
                        current = nodes.front();
                        currentArr.push_back(current -> val);
                        if (current -> left != nullptr) {                    
                            nodes.push_back(current -> left);
                        }
                        if (current -> right != nullptr) {                    
                            nodes.push_back(current -> right);
                        }
                        nodes.pop_front();
                    }
            }
            answer.push_back(currentArr);
            currentArr = {};
            ++counter;
        }
        return answer;
    }
};