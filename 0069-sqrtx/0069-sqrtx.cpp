class Solution {
public:
    int mySqrt(int x) {
        if (x<2) {
            return x;
        }
        int step = INT_MAX/2;
        int guess = step;        
        while (!(guess <= x/guess && (guess+1) > x/(guess+1))) {
            if (step != 1) {
                step /= 2;
            }
            if (guess < x/guess) {
                guess += step;
            } else {
                guess -= step;
            }
        } 
        return guess;
    }
};