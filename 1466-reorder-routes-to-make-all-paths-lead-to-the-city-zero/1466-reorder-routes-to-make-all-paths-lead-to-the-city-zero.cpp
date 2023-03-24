class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, int parent, int node) {
        for (auto& [child, rev] : adj[node]) {
            if (child != parent) {
                dfs(adj, node, child);
                count += rev;
            }
        }
    }
    int minReorder(int& n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back({connection[1], 1});
            adj[connection[1]].push_back({connection[0], 0});
        }
        dfs(adj, -1, 0);
        return count;
    }
    
private:
    int count = 0;
};