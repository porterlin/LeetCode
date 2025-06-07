class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0, n = isConnected.size();
        vector<bool> vis(n);

        auto dfs = [&](this auto&& dfs, int i) -> void {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && !vis[j]) {
                    vis[j] = 1;
                    dfs(j);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans++;
                dfs(i);
            }
        }

        return ans;
    }
};