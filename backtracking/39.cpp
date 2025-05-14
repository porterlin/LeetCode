class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&& dfs, int i, int t) {
            if (t < 0 || i == candidates.size())
                return;

            if (t == 0) {
                ans.push_back(path);
                return;
            }

            dfs(i + 1, t);

            path.push_back(candidates[i]);
            dfs(i, t - candidates[i]);
            path.pop_back();
        };

        dfs(0, target);
        return ans;
    }
};