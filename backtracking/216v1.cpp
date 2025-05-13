class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        auto dfs = [&](this auto&& dfs, int i, int t) {
            int d = k - path.size();
            if (t < 0 || t > ((2 * i - d + 1) * d / 2)) // 當前還需枚舉 d 個，如果此時可枚舉的數中最大 d 個數的和小於 t，直接 return
                return;
            if (path.size() == k) {
                if (t == 0)
                    ans.push_back(path);
                return;
            }

            for (int j = i; j > 0; j--) {
                path.push_back(j);
                dfs(j - 1, t - j);
                path.pop_back();
            }
        };

        dfs(9, n);
        return ans;
    }
};