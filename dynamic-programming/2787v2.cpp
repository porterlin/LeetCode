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

        vector<vector<long long>> dp(m, vector<long long>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i < m; i++) {
            int val = pow(i, x);
            for (int c = 0; c <= n; c++) {
                if (c < val)
                    dp[i][c] = dp[i - 1][c] % MOD;
                else
                    dp[i][c] = (dp[i - 1][c] + dp[i - 1][c - val]) % MOD;
            }
        }
        return dp[m - 1][n];
    }
};