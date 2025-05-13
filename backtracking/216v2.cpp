class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&& dfs, int i, int t) {
            int d = k - path.size();
            if (i < 0 || t < 0 || t > ((2 * i - d + 1) * d / 2))
                return;
            if (path.size() == k) {
                if (t == 0)
                    ans.push_back(path);
                return;
            }

            dfs(i - 1, t);

            path.push_back(i);
            dfs(i - 1, t - i);
            path.pop_back();
        };

        dfs(9, n);
        return ans;
    }
};