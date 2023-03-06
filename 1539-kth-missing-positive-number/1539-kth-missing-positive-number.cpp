class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size();
        int mid;
        while (start < end) {
            mid = (start + end) / 2;
            if ((arr[mid]) > mid + k) {
                end = mid;                
            } else {
                start = mid + 1;
            }
        }
        return start + k;
    }
};