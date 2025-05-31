class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 1)
            return grid[0][0];
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, INT_MAX));
        ranges::fill(dp[n], 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= n; j++) {
                int val = INT_MAX;
                for (int k = 1; k <= n; k++) {
                    if (j == k)
                        continue;
                    val = min(val, dp[i + 1][k]);
                }
                dp[i][j] = val + grid[i][j - 1];
            }
        }
        return ranges::min(dp[0]);
    }
};