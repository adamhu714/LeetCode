class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> vecRan(26, 0), vecMag(26, 0);
        for (char i : ransomNote) {
            vecRan[i - 'a'] +=1;
        }
        for (char i : magazine) {
            vecMag[i - 'a'] +=1;
        }
        for (int i = 0; i < vecRan.size(); ++i) {
            if (vecRan[i] > vecMag[i]) {
                return false;
            }
        }
        return true;
    }
};