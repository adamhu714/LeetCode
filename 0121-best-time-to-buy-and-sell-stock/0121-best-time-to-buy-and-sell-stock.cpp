class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minVal = INT_MAX;
        for (int i : prices) {
            profit = max(profit, i - minVal);
            minVal = min(minVal, i);
        }
        return profit;
    }
};