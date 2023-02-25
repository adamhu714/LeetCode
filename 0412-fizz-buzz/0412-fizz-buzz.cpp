class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 0; i < n; ++i) {
            if ((i+1) % 15 == 0) {
                res.at(i) = "FizzBuzz";
            } else if ((i+1) % 3 == 0) {
                res.at(i) = "Fizz";
            } else if ((i+1) % 5 == 0) {
                res.at(i) = "Buzz";
            } else {
                res.at(i) = to_string(i+1);
            }
        }
        return res;
    }
};