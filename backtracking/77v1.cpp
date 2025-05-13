class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&& dfs, int i) {
            int d = k - path.size();

            if (i < d)
                return;
            if (path.size() == k) {
                ans.push_back(path);
                return;
            }

            for (int j = i; j > 0; j--) {
                path.push_back(j);
                dfs(j - 1);
                path.pop_back();
            }
        };

        dfs(n);
        return ans;
    }
};