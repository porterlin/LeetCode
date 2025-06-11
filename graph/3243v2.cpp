class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; i++)
            graph[i].push_back(i + 1);

        vector<int> vis(n, -1);
        auto bfs = [&](int i) -> int {
            queue<int> q;
            q.push(0);
            for (int step = 1;; step++) {
                int qsize = q.size();
                while (qsize--) {
                    int val = q.front();
                    q.pop();
                    for (int j = 0; j < graph[val].size(); j++) {
                        if (graph[val][j] == n - 1)
                            return step;
                        if (vis[graph[val][j]] != i) {
                            vis[graph[val][j]] = i;
                            q.push(graph[val][j]);
                        }
                    }
                }
            }
        };

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            graph[queries[i][0]].push_back(queries[i][1]);
            ans[i] = bfs(i);
        }
        return ans;
    }
};