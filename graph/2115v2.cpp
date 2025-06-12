class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n = recipes.size();
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string>> graph;
        for (int i = 0; i < n; i++) {
            for (auto& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }

        queue<string> q;
        for (auto& a : supplies) {
            q.push(a);
        }

        vector<string> ans;
        while (!q.empty()) {
            string u = q.front();
            q.pop();
            for (auto& v : graph[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    ans.push_back(v);
                    q.push(v);
                }
            }
        }
        return ans;
    }
};