class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (obstacleGrid[i - 1][j - 1] == 1)
                    continue;
                if ((i != 1 && obstacleGrid[i - 2][j - 1] != 1) || i == 1)
                    dp[i][j] += dp[i - 1][j];
                if ((j != 1 && obstacleGrid[i - 1][j - 2] != 1) || j == 1)
                    dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};