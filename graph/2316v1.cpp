class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {  
        int cnt = 0;
        vector<bool> vis(n);
        vector<int> check;
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

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cnt = 0;
                dfs(i);
                check.push_back(cnt);
            }
        }

        long long ans = 0;
        vector<long long> pre(check.size() + 1);
        
        for (int i = 0; i < check.size(); i++)
            pre[i + 1] = pre[i] + check[i];
        
        for (int i = check.size() - 1; i >= 0; i--)
            ans += 1LL * check[i] * pre[i];

        return ans;
    }
};