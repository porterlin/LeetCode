// 再優化到只需要一維陣列
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, 1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int c = coins[i]; c <= amount; c++) {
                dp[c] = min(dp[c], dp[c - coins[i]] + 1);
            }
        }

        int& ans = dp[amount];
        return ans == 1e9 ? -1 : ans;
    }
};