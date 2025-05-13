class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&& dfs, int i) {
            if (path.size() == k) {
                ans.push_back(path);
                return;
            }
            int d = k - path.size();
            if (i < d || i == 0)
                return;

            dfs(i - 1);

            path.push_back(i);
            dfs(i - 1);
            path.pop_back();
        };

        dfs(n);
        return ans;
    }
};