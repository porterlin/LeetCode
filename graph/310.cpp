class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        vector<int> indegree(n);
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            indegree[e[0]]++;
            indegree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1)
                q.push(i);
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.clear();
            int qsize = q.size();
            while (qsize--) {
                int u = q.front();
                q.pop();
                ans.push_back(u);
                for (auto& v : graph[u]) {
                    indegree[v]--;
                    if (indegree[v] == 1)
                        q.push(v);
                }
            }
        }
        return ans;
    }
};