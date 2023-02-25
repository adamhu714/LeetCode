class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;
        vector<int> vecMag(26, 0);
        for (char i : magazine) ++vecMag[i - 'a'];
        for (char i : ransomNote) if (--vecMag[i - 'a'] < 0) return false;
        return true;
    }
};