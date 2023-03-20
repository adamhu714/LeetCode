class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums) {
            if (s.find(i) != s.end()) {
                s.erase(i);
            } else {
                s.insert(i);
            }
        }
        return *s.begin();
    }
};