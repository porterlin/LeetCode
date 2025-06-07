class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {  
        long long cnt = 0;
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int s = edge[0], t = edge[1];
            adj[s].push_back(t);
            adj[t].push_back(s);
        }

        auto dfs = [&](this auto&& dfs, int i) -> void {
            vis[i] = 1;
            cnt++;
            for (auto& next : adj[i]) {
                if (!vis[next])
                    dfs(next);
            }
        };

        long long ans = 0, total = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt = 0;
                dfs(i);
                ans += cnt * total;
                total += cnt;
            }
        }
        return ans;
    }
};