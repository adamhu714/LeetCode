class Solution {
public:
    void dfs(vector<vector<int>> &adj, int i, vector<bool> &visited) {
        if (!visited[i]) {
            visited[i] = true;
            for (int j : adj[i]) {
                dfs(adj, j, visited);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        
        vector<vector<int>> adj(n);
        for (auto& connection : connections) {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
        }
        
        int islands = 0;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(adj, i, visited);
                ++islands;
            }
        }
        return islands - 1;
    }
};