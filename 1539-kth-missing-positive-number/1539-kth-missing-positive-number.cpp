class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int start = 0;
        int end = arr.size() - 1;
        if (arr[end] < end + 1 + k) {
            return end + 1 + k;
        }
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