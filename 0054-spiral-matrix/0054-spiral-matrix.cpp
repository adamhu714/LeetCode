class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int rowStart = 0;
        int rowEnd = m - 1;
        int columnStart = 0;
        int columnEnd = n - 1;
        
        while (ans.size() < m*n) {
            for (int i = columnStart; i <= columnEnd && ans.size() < m*n; ++i) {
                ans.push_back(matrix[rowStart][i]);
            }
            for (int i = ++rowStart; i <= rowEnd && ans.size() < m*n; ++i) {
                ans.push_back(matrix[i][columnEnd]);
            }
            for (int i = --columnEnd; i >= columnStart && ans.size() < m*n; --i) {
                ans.push_back(matrix[rowEnd][i]);
            }
            for (int i = --rowEnd; i >= rowStart && ans.size() < m*n; --i) {
                ans.push_back(matrix[i][columnStart]);
            }
            ++columnStart;
        } 
        return ans;
    }
};