class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long test;
        long long r;
        int max_time = 0;
        for (int t : time) {
            max_time = max(max_time, t);
        }
        r = 1LL * max_time * totalTrips;
        long long l = 1;
        long long total = 0;
        while (l < r) {
            test = (l/2 + r/2);
            total = 0;
            for (int t : time) {
                total += test / t;
            }
            if (total >= totalTrips) {
                r = test;
            } else {
                l = test + 1;
            }
        }
        return l;
    }
};