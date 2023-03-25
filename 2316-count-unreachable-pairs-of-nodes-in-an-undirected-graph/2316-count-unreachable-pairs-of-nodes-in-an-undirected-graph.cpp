class Solution {
public:
    int dfs(vector<vector<int>>& adj, int node) {
        visited.insert(node);
        int count = 1;
        for (int j : adj[node]) {
            if (visited.find(j) == visited.end()) {
                count += dfs(adj, j);
            }
        }
        return count;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& v : edges) {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        
        for (int i = 0; i < n; ++i) {
            if (visited.find(i) == visited.end()) {
                islandsLens.push_back(dfs(adj, i));
            }
        }
        
        long long answer = 0;
        int sumofL = 0;
        
        for(std::vector<int>::iterator it = islandsLens.begin(); it != islandsLens.end(); ++it)
            sumofL += *it;
        
        for (int i = 0; i < islandsLens.size() - 1; ++i) {
            sumofL -= islandsLens[i];
            answer += 1LL * islandsLens[i] * sumofL;
        }
        return answer;
    }

private:
    unordered_set<int> visited;
    vector<int> islandsLens;
};