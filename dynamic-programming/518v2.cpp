class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(amount + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= amount; c++) {
                if (c < coins[i])
                    dp[i + 1][c] = dp[i][c];
                else
                    dp[i + 1][c] = dp[i][c] + dp[i + 1][c - coins[i]];
            }
        }
        return dp[n][amount];
    }
};