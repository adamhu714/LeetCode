class Solution {
public:
    bool isValid(string s) {
        stack<char> paren;
        for (char i : s) {
            if (i == '(' || i == '{' || i == '[') {
                paren.push(i);    
            } else if (not paren.empty() && (i == ')' && paren.top() == '(' || i == '}' && paren.top() == '{' || i == ']' && paren.top() == '[')) {
                paren.pop();  
            } else {
                return false;
            }
        }
        if (paren.empty()) {
            return true;
        }
        return false;
    }
};