class Solution {
public:
    int numSquares(int n) {
        int w = ceil(sqrt(n));
        vector<vector<int>> dp(2, vector<int>(n + 1, 1e9));
        dp[1][0] = 0;
        for (int i = 1; i <= w; i++) {
            for (int c = 0; c <= n; c++) {
                if (c < i * i)
                    dp[(i + 1) % 2][c] = dp[i % 2][c];
                else
                    dp[(i + 1) % 2][c] = min(dp[i % 2][c], dp[(i + 1) % 2][c - i * i] + 1);
            }
        }
        return dp[(w + 1) % 2][n];
    }
};