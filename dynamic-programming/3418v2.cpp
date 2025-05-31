class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector dp(m + 1, vector(n + 1, array<int, 3>{INT_MIN / 2, INT_MIN / 2, INT_MIN / 2}));
        dp[0][1] = {0, 0, 0};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++) {
                    dp[i + 1][j + 1][k] = max(dp[i][j + 1][k], dp[i + 1][j][k]) + coins[i][j];
                    if (coins[i][j] < 0 && k > 0)
                        dp[i + 1][j + 1][k] = max({dp[i + 1][j + 1][k], dp[i][j + 1][k - 1], dp[i + 1][j][k - 1]});
                }
            }
        }
        return dp[m][n][2];
    }
};