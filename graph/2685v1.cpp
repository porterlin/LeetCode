class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int ans = 0;
        vector<bool> vis(n);
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            int s = e[0], t = e[1];
            graph[s].push_back(t);
            graph[t].push_back(s);
        }

        int cntNode = 0, cntEdges = 0;
        vector<vector<bool>> edg(n, vector<bool>(n));
        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (!vis[i]) {
                cntNode++;
                vis[i] = 1;
            }
            for (auto& next : graph[i]) {
                if (!edg[i][next]) {
                    cntEdges++;
                    edg[i][next] = 1;
                    edg[next][i] = 1;
                    dfs(next);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cntNode = cntEdges = 0;
                dfs(i);
                if (cntNode * (cntNode - 1) / 2 == cntEdges)
                    ans++;
            }
        }
        return ans;
    }
};