class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;

        auto dfs = [&](this auto&& dfs, int i) -> void {
            if (i == n - 1) {
                ans.push_back(path);
                return;
            }
            
            for (auto& next : graph[i]) {
                path.push_back(next);
                dfs(next);
                path.pop_back();
            }
        };

        path.push_back(0);
        dfs(0);
        return ans;
    }
};