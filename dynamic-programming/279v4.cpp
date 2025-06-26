class Solution {
public:
    int numSquares(int n) {
        int w = ceil(sqrt(n));
        vector<int> dp(n + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= w; i++) {
            for (int c = i * i; c <= n; c++) {
                dp[c] = min(dp[c], dp[c - i * i] + 1);
            }
        }
        return dp[n];
    }
};