class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> check(numCourses, vector<int>(numCourses));
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]);
            indegree[p[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto& v : graph[u]) {
                check[u][v] = 1;
                for (int i = 0; i < numCourses; i++)
                    check[i][v] |= check[i][u];

                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }

        int index = 0;
        vector<bool> ans(queries.size());
        for (auto& q : queries) {
            ans[index++] = check[q[0]][q[1]];
        }
        return ans;
    }
};