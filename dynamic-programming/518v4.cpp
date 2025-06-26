class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> dp(amount + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = coins[i]; c <= amount; c++) {
                dp[c] += dp[c - coins[i]];
            }
        }
        return dp[amount];
    }
};