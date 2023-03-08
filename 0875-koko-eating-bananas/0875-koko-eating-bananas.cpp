class Solution {
public:
    bool fastEnough(const vector<int>& piles, const int& h, const int& k) {
        int totalHours = 0;
        for (const auto pile : piles) {
            totalHours += (pile / k) + (pile % k != 0);
        }
        return (totalHours <= h);
    }
    int minEatingSpeed(vector<int>& piles, int& h) {
        int kr = 1000000000; //*max_element(piles.begin(), piles.end());
        int kl = 1;
        int k;
        
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