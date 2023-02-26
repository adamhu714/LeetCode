class Solution {
public:
    
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1));
        for (int i = 0; i <= m; ++i){
            for (int j = 0; j <= n; ++j){
                if (i == 0 || j == 0) {
                    continue;
                }
                if (word1[i-1] == word2[j-1]) {
                    memo[i][j] = 1 + memo[i-1][j-1];
                } else {
                    memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
                }
            }   
        }
        
        return m + n - 2*memo[m][n];
    }
};