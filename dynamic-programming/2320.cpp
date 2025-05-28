class Solution {
public:
    int countHousePlacements(int n) {
        const int MOD = 1e9 + 7;
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        
        return 1LL * dp[n] * dp[n] % MOD;
    }
};