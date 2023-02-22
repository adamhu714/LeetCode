class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        // binary search for least weight capacity.
        
        // test whether current weight is an able capacity - if it is, reduce
        // right end of binary search, if not raise left side of search
        
        // start with left side = 0, right = sum of weights
        
        // to check if able capacity, loop through weights, add to counter when 
        // over capcity and compare to days value
        
        
        int start = 0;
        int end = std::reduce(weights.begin(), weights.end());
        int mid = 0;
        while (start <= end) {
            mid = (start + end) / 2;
            if (ableCapacity(weights, mid, days)) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        cout << start << " " << mid << " " << end;
        return (ableCapacity(weights, start, days)) ? start : end ;
        
    }
    
    bool ableCapacity(vector<int>& weights, int capacity, int days) {
        int counting = 0;
        int dayCount = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (weights[i] > capacity) {
                return false;
            }
            counting += weights[i];
            if (counting > capacity) {
                counting = weights[i];
                if (++dayCount > days) {
                    return false;
                }
            }
        }
        return true;
    }
    
};