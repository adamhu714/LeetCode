class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayS = haystack.size();
        int neeS = needle.size();
        for (int i = 0; i <= hayS - neeS; ++i) {
            for (int j = 0; j < neeS; ++j) {
                if (haystack[i+j] != needle[j]) {
                    break;
                }
                if (j == neeS - 1) {
                    return i;
                }
            }
        }
        return -1;
    }
};