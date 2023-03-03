class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26);
        for (char c : word) {
            ++freq[c-'a'];
        }
        vector<int> copied;
        bool passed = false;
        int norm;
        for (int i = 0; i < 26; ++i) {
            copied = freq;
            if (copied[i] == 0) {
                continue;
            }
            copied[i]--;
            passed = true;
            for (int j = 0; j < 26; ++j) {
                if (copied[j] != 0) {
                    norm = copied[j];
                }
            }
            for (int j = 0; j < 26; ++j) {
                if (copied[j] != norm && copied[j] != 0) {
                    passed = false;
                    break;
                }
            }
            if (passed == true) {
                return true;
            }
        }
        return false;
    }
};