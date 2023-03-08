class Solution {
public:
    bool fastEnough(vector<int>& piles, int h, int k) {
        int totalHours = 0;
        for (int i = 0; i < piles.size(); ++i) {
            totalHours += (piles[i] / k) + (piles[i] % k != 0);
        }
        return (totalHours <= h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int kr = INT_MAX/2; //*max_element(piles.begin(), piles.end());
        int kl = 1;
        int k = 0;
        
        while (kl < kr) {
            k = (kl + kr) / 2;
            if (fastEnough(piles, h, k)) {
                kr = k;
            } else {
                kl = k + 1;
            }
        }
        return kl;
    }
};