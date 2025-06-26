class Solution {
public:
    int numSquares(int n) {
        int w = ceil(sqrt(n));
        vector<vector<int>> memo(w + 1, vector<int>(n + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int c) -> int {
            if (i < 1)
                return c == 0 ? 0 : 1e9;
            if (memo[i][c] != -1)
                return memo[i][c];
            if (c < i * i)
                return memo[i][c] = dfs(i - 1, c);

            return memo[i][c] = min(dfs(i - 1, c), dfs(i, c - i * i) + 1);
        };
        return dfs(w, n);
    }
};