class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector memo(m, vector(n, array<int, 3>{INT_MIN, INT_MIN, INT_MIN}));
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> int {
            if (i < 0 || j < 0)
                return INT_MIN;
            if (i == 0 && j == 0) {
                if (k > 0 && coins[i][j] < 0)
                    return 0;
                return coins[i][j];
            }
            if (memo[i][j][k] != INT_MIN)
                return memo[i][j][k];

            int val = max(dfs(i - 1, j, k), dfs(i, j - 1, k)) + coins[i][j]; // 選
            if (coins[i][j] < 0 && k > 0)
                val = max({val, dfs(i - 1, j, k - 1), dfs(i, j - 1, k - 1)}); // 不選

            return memo[i][j][k] = val;
        };
        return dfs(m - 1, n - 1, 2);
    }
};