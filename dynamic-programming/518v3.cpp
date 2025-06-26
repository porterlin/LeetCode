class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(2, vector<unsigned long long>(amount + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= amount; c++) {
                if (c < coins[i])
                    dp[(i + 1) % 2][c] = dp[i % 2][c];
                else
                    dp[(i + 1) % 2][c] = dp[i % 2][c] + dp[(i + 1) % 2][c - coins[i]];
            }
        }
        return dp[n % 2][amount];
    }
};