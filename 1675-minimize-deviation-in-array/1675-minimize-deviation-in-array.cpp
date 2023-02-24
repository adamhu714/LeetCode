class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        int minN = INT_MAX;
        int res = INT_MAX;
        priority_queue<int> pq;
        
        for (int& n : nums) {
            n = n % 2 ? n *= 2 : n;
            minN = min(minN, n);
            pq.push(n);
        }
        
        while (pq.top() % 2 == 0) {
            res = min(res, pq.top() - minN);
            minN = min(minN, pq.top()/2);
            pq.push(pq.top()/2);
            pq.pop();
        }
        return min(res, pq.top() - minN);
    }
};