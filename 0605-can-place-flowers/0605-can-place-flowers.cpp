class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if (n == 0) {
            return true;
        }
        if (flowerbed.size() == 1) {
            if (flowerbed[0] + n < 2) {
                return true;
            } else {
                return false;
            }
        }
        if (flowerbed[0] + flowerbed[1] == 0) {
            ++flowerbed[0];
            --n;
        }
        
        for (int i = 2; i < flowerbed.size() - 1; ++i) {
            if (n == 0) {
                return true;
            }
            if (flowerbed[i-1] + flowerbed[i] + flowerbed[i+1] == 0) {
                ++flowerbed[i++];
                --n;
            }
        }
        
        if (n == 0 || (n == 1 && flowerbed[flowerbed.size() - 2] + flowerbed[flowerbed.size() - 1] == 0)) {
            return true;
        }
        
        return false;
    }
};