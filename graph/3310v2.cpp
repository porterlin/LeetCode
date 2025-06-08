class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for (auto& a : invocations) {
            int s = a[0], t = a[1];
            adj[s].push_back(t);
        }

        auto dfs = [&](this auto&& dfs, int i) -> void {
            vis[i] = 1;
            for (auto& next : adj[i]) {
                if (!vis[next])
                    dfs(next);
            }
        };
        dfs(k);

        for (auto& a : invocations) {
            int s = a[0], t = a[1];
            if (!vis[s] && vis[t]) {
                vector<int> ans(n);
                iota(ans.begin(), ans.end(), 0);
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};