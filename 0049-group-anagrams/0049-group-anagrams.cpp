class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        
        for (const string& s : strs) {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        
        for (const auto& [i, v] : mp) {
            ans.push_back(v);
        }
        
        return ans;
    }
};