class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;
        
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for (auto& a : connections) {
            int s = a[0], t = a[1];
            adj[s].push_back(t);
            adj[t].push_back(s);
        }

        auto dfs = [&](this auto&& dfs, int i) -> void {
            vis[i] = 1;
            for (auto& next : adj[i]) {
                if (!vis[next])
                    dfs(next);
            }
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i);
            }
        }
        return ans - 1;
    }
};