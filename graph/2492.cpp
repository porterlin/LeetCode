class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX;
        vector<bool> vis(n + 1);
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& r : roads) {
            int s = r[0], t = r[1], d = r[2];
            adj[s].push_back({t, d});
            adj[t].push_back({s, d});
        }

        auto dfs = [&](this auto&& dfs, int i) -> void {
            vis[i] = 1;
            for (auto& [next, distance] : adj[i]) {
                ans = min(ans, distance);
                if (!vis[next])
                    dfs(next);
            }
        };

        dfs(1);
        return ans;
    }
};