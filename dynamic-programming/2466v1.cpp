class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1e9 + 7;
        int start = max(zero, one);
        vector<int> dp(high + start + 1);
        dp[zero + start]++;
        dp[one + start]++;
        
        int ans = 0;
        for (int i = 0; i <= high; i++) {
            dp[i + start] += (dp[i - zero + start] + dp[i - one + start]) % MOD;
            if (i >= low && i <= high)
                ans = (ans + dp[i + start]) % MOD;
        }
        return ans;
    }
};