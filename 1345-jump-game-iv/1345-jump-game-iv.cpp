class Solution {
public:
    int minJumps(vector<int>& arr) {
        // make dictionary with element value as key and indexes as values to then get the i to j edges
        
        unordered_map<int, vector<int>> mp;
        int arrSize = arr.size();
        if (arrSize < 2) {
            return 0;
        }
        for (int i = 0; i < arrSize; ++i) {
            mp[arr[i]].push_back(i);
        }        
        
        // bfs through graph, keep track of number of steps, until reach last index
        
        deque<int> dq;
        unordered_set<int> visited;
        dq.push_back(0);
        visited.insert(0);
        int dqSize;
        int current;
        int step = 0;
        
        while (!dq.empty()) {
            dqSize = dq.size();
            for (int i = 0; i < dqSize; ++i) {
                current = dq.front();
                
                if (current == arrSize - 1) {
                    return step;
                }
                
                for (int next : mp[arr[current]]) {
                    if (visited.find(next) == visited.end()) {
                        dq.push_back(next);
                        visited.insert(next);
                    }
                }
                
                // clear visited nodes
                mp[arr[current]].clear();
                
                for (int next : {current - 1, current + 1}) {
                    if (next > 0 && next < arrSize && visited.find(next) == visited.end()) {
                        dq.push_back(next);
                        visited.insert(next);
                    }
                }
                dq.pop_front();
            }
            ++step;
        }
        return -1;
    }
};