class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> st(recipes.begin(), recipes.end());
        unordered_set<string> have(supplies.begin(), supplies.end());
        unordered_map<string, int> mp;
        unordered_map<int, string> mp1;
        int n = 0;
        for (auto& ing : ingredients) {
            for (auto& a : ing) {
                if (!mp.count(a)) {
                    mp[a] = n;
                    mp1[n] = a;
                    n++;
                }
            }
        }
        for (auto& a : recipes) {
            if (!mp.count(a)) {
                mp[a] = n;
                mp1[n] = a;
                n++;
            }
        }
        
        vector<int> indegree(n);
        vector<vector<int>> graph(n);
        for (int i = 0; i < ingredients.size(); i++) {
            for (int j = 0; j < ingredients[i].size(); j++) {
                string& str = ingredients[i][j];
                graph[mp[str]].push_back(mp[recipes[i]]);
                indegree[mp[recipes[i]]]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<string> ans;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (have.count(mp1[u]) == 0)
                continue;
            for (auto& v : graph[u]) {
                indegree[v]--;
                if (st.count(mp1[v]) && indegree[v] == 0) {
                    ans.push_back(mp1[v]);
                    q.push(v);
                    have.insert(mp1[v]);
                }
            }
        }
        return ans;
    }
};