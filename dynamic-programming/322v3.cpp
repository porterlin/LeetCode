// 遞推優化空間複雜度到 O(target)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(2, vector<int>(amount + 1, 1e9));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= amount; c++) {
                if (c < coins[i])
                    dp[(i + 1) % 2][c] = dp[i % 2][c];
                else
                    dp[(i + 1) % 2][c] = min(dp[i % 2][c], dp[(i + 1) % 2][c - coins[i]] + 1);
            }
        }

        int& ans = dp[n % 2][amount];
        return ans == 1e9 ? -1 : ans;
    }
};