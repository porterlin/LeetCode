class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        int ans = 0;
        vector<int> dp(high + 1);
        dp[0] = 1;
        for (int i = 1; i <= high; i++) {
            if (i >= zero)
                dp[i] = dp[i - zero];
            if (i >= one)
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            if (i >= low)
                ans = (ans + dp[i]) % MOD;
        }
        return ans;
    }
};