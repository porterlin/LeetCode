// 遞推
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2)
            return 0;
        target /= 2;

        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= target; c++) {
                if (c < nums[i])
                    dp[i + 1][c] = dp[i][c];
                else
                    dp[i + 1][c] = dp[i][c] + dp[i][c - nums[i]];
            }
        }
        return dp[n][target];
    }
};