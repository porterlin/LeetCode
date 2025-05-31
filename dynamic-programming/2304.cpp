class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                dp[i + 1][j] = INT_MAX;
                for (int k = 0; k < n; k++) {
                    // grid[i][k] -> grid[i + 1][j]
                    if (dp[i][k] + grid[i][k] + moveCost[grid[i][k]][j] < dp[i + 1][j])
                        dp[i + 1][j] = dp[i][k] + grid[i][k] + moveCost[grid[i][k]][j];
                }
            }
        }

        for (int i = 0; i < n; i++)
            dp[m - 1][i] += grid[m - 1][i];

        return ranges::min(dp[m - 1]);
    }
};