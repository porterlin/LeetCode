class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int s = edge[0], t = edge[1];
            adj[s].push_back(t);
            adj[t].push_back(s);
        }

        auto dfs = [&](this auto&& dfs, int i) -> bool {
            vis[i] = 1;
            if (i == destination)
                return true;
            for (auto& next : adj[i]) {
                if (!vis[next] && dfs(next))
                    return true;
            }
            return false;
        };
        return dfs(source);
    }
};