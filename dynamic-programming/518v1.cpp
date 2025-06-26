class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int c) -> int {
            if (i < 0)
                return c == 0;
            if (memo[i][c] != -1)
                return memo[i][c];
            if (c < coins[i])
                return memo[i][c] = dfs(i - 1, c);

            return memo[i][c] = dfs(i - 1, c) + dfs(i, c - coins[i]);
        };
        return dfs(n - 1, amount);
    }
};