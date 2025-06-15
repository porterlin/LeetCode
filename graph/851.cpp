class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int> indegree(n);
        vector<vector<int>> graph(n);
        for (auto& r : richer) {
            graph[r[0]].push_back(r[1]);
            indegree[r[1]]++;
        }

        queue<int> q;
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& v : graph[u]) {
                indegree[v]--;
                if (quiet[ans[u]] < quiet[ans[v]])
                    ans[v] = ans[u];
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        return ans;
    }
};