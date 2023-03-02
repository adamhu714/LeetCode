class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.size() < 2) {
            return chars.size();
        }
        int i = 0;
        char current = chars[0];
        int count = 1;
        for (int j = 1; j < chars.size(); ++j) {
            if (chars[j] != current) {
                if (count == 1) {
                    chars[i] = current;
                    current = chars[j];
                    count = 1;
                    ++i;
                } else {
                    chars[i] = current;
                    ++i;
                    string countStr = to_string(count);
                    for (char cntC : countStr) {
                        chars[i] = cntC;
                        ++i;
                    }
                    current = chars[j];
                    count = 1;
                }
            } else {
                ++count;
            }
        }
        if (count == 1) {
            chars[i] = current;
            ++i;
        } else {
            chars[i] = current;
            ++i;
            string countStr = to_string(count);
            for (char cntC : countStr) {
                chars[i] = cntC;
                ++i;
            }
        }
        return i;
    }
};