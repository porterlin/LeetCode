class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges)
            graph[e[0]].push_back(e[1]);

        vector<bool> vis(n);
        auto dfs = [&](this auto&& dfs, int i) -> void {
            for (auto& next : graph[i]) {
                if (!vis[next]) {
                    vis[next] = 1;
                    dfs(next);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i])
                dfs(i);
        }

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (!vis[i])
                ans.push_back(i);
        return ans;
    }
};