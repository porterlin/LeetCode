class Solution {
public:
    int numberOfWays(int n, int x) {
        const int MOD = 1e9 + 7;
        int m;
        for (int i = 1;; i++) {
            if (pow(i, x) > n) {
                m = i;
                break;
            }
        }

        vector<long long> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i < m; i++) {
            int val = pow(i, x);
            for (int c = n; c >= val; c--) {
                dp[c] = (dp[c] + dp[c - val]) % MOD;
            }
        }
        return dp[n];
    }
};