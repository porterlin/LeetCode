class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        unordered_set<int> st;
        vector<bool> vis(n);
        vector<vector<int>> adj(n);
        for (auto& a : invocations) {
            int s = a[0], t = a[1];
            adj[s].push_back(t);
        }

        int valid = true;
        auto dfs = [&](this auto&& dfs, int i, bool check) -> void {
            vis[i] = 1;
            if (check) {
                st.insert(i);
            }

            for (auto& next : adj[i]) {
                if (!vis[next])
                    dfs(next, check);
                if (!check && st.count(next))
                    valid = false;
            }
        };

        dfs(k, 1);

        for (int i = 0; i < n; i++) {
            if (!st.count(i))
                dfs(i, 0);
        }

        if (!valid) {
            vector<int> ans(n);
            iota(ans.begin(), ans.end(), 0);
            return ans;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!st.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};