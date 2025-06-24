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

        vector<vector<long long>> dp(2, vector<long long>(n + 1));
        dp[0][0] = 1;
        for (int i = 1; i < m; i++) {
            int val = pow(i, x);
            for (int c = 0; c <= n; c++) {
                if (c < val)
                    dp[i % 2][c] = dp[(i - 1) % 2][c] % MOD;
                else
                    dp[i % 2][c] = (dp[(i - 1) % 2][c] + dp[(i - 1) % 2][c - val]) % MOD;
            }
        }
        return dp[(m - 1) % 2][n];
    }
};