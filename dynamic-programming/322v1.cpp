// 記憶化搜索
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int c) -> int {
            if (i < 0)
                return c == 0 ? 0 : 1e9;
            if (memo[i][c] != -1)
                return memo[i][c];
            
            if (c < coins[i])
                return memo[i][c] = dfs(i - 1, c);
            return memo[i][c] = min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1);
        };

        int ans = dfs(n - 1, amount);
        return ans == 1e9 ? -1 : ans;
    }
};