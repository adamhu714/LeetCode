class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, vector<bool>& visit, int node) {
        visit[node] = true;
        for (auto& edge : adj[node]) {
            answer = min(answer, edge.second);
            if (!visit[edge.first]) {
                dfs(adj, visit, edge.first);
            }
        }
    };
    
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        vector<bool> visit(n + 1);
        for (auto& v : roads) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        dfs(adj, visit, 1);
        return answer;
    }
private:
    int answer = INT_MAX;
};