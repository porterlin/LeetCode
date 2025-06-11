class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (int i = 0; i < n - 1; i++)
            graph[i].push_back(i + 1);

        int index = 0;
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            graph[queries[i][0]].push_back(queries[i][1]);

            int cnt = 0;
            vector<bool> vis(n);
            queue<int> q;
            q.push(0);
            bool check = false;
            while (!q.empty()) {
                cnt++;
                int qsize = q.size();
                while (qsize--) {
                    int val = q.front();
                    q.pop();
                    int j = 0;
                    for (; j < graph[val].size(); j++) {
                        if (graph[val][j] == n - 1) {
                            check = true;
                            break;
                        }
                        if (!vis[graph[val][j]]) {
                            vis[graph[val][j]] = 1;
                            q.push(graph[val][j]);
                        }
                    }
                    if (check)
                        break;
                }
                if (check)
                    break;
            }
            ans[index++] = cnt;
        }
        return ans;
    }
};