class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int sumI = 0;
        int richest = 0;
        for (int i = 0; i < accounts.size(); ++i) {
            for (int j = 0; j < accounts[i].size(); ++j) {
                sumI += accounts[i][j];
            }
            richest = max(richest, sumI);
            sumI = 0;
        }
        return richest;
    }
};