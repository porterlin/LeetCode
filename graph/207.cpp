class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> graph(numCourses);
        for (auto& p : prerequisites) {
            graph[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        int check = 0;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            check++;
            for (auto& v : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0)
                    q.push(v);
            }
        }
        return check == numCourses;
    }
};