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

        int cntNode, cntEdges;
        auto dfs = [&](this auto&& dfs, int i) -> void {
            vis[i] = 1;
            cntNode++;
            cntEdges += graph[i].size();
            for (auto& next : graph[i]) {
                if (!vis[next]) {
                    dfs(next);
                }
            }
        };

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                cntNode = cntEdges = 0;
                dfs(i);
                if (cntNode * (cntNode - 1) == cntEdges)
                    ans++;
            }
        }
        return ans;
    }
};