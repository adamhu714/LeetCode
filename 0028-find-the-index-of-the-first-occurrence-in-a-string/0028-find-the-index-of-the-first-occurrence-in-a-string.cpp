class Solution {
public:
    int strStr(string haystack, string needle) {
        int hayS = haystack.size();
        int neeS = needle.size();
        int i = 0;
        bool okay;
        while (i <= hayS - neeS) {
            if (haystack[i] == needle[0]) {
                okay = true;
                for (int j = i; j < i + neeS; ++j) {
                    if (haystack[j] != needle[j - i]) {
                        okay = false;
                    }
                }
                if (okay) {
                    return i;
                }
            }
            ++i;
        }
        return -1;
    }
};