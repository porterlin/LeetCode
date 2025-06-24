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

        vector<vector<long long>> memo(m, vector<long long>(n + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, long long c) -> long long {
            if (i == 0)
                return c == 0;
            if (memo[i][c] != -1)
                return memo[i][c];
            if (c < pow(i, x))
                return memo[i][c] = dfs(i - 1, c) % MOD;
            
            return memo[i][c] = (dfs(i - 1, c) + dfs(i - 1, c - pow(i, x))) % MOD;
        };

        return dfs(m - 1, (long long)n);
    }
};