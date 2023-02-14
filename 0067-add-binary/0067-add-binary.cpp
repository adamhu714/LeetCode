class Solution {
public:
    string addBinary(string a, string b) {
        
        string s = "";
        int c = 0, i = a.size() - 1, j = b.size() - 1;
        
        while (i > -1 || j > -1 || c > 0){
            
            c += i > -1 ? a[i--] - '0' : 0;
            c += j > -1 ? b[j--] - '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
                
        }
        return s;
    }
};