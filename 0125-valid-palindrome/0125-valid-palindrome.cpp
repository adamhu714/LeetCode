class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](char c) {return !isalnum(c, locale());}), s.end());
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
    }
};

// bool isPalindrome(string s) {
//     for (int i = 0, j = s.size() - 1; i < j; i++, j--) { // Move 2 pointers from each end until they collide
//         while (isalnum(s[i]) == false && i < j) i++; // Increment left pointer if not alphanumeric
//         while (isalnum(s[j]) == false && i < j) j--; // Decrement right pointer if no alphanumeric
//         if (toupper(s[i]) != toupper(s[j])) return false; // Exit and return error if not match
//     }
    
//     return true;
// }

// bool isPalindrome(string s) {
//     s.erase(remove_if(s.begin(), s.end(), isalnum),
//     s.end());
//     transform(s.begin(), s.end(), s.begin(), ::toupper);
//     return equal(s.begin(), s.begin() + s.size() / 2, s.rbegin());
// }
