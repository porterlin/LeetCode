// 遞推優化空間複雜度到 O(target)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2)
            return 0;
        target /= 2;

        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(target + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= target; c++) {
                if (c < nums[i])
                    dp[(i + 1) % 2][c] = dp[i % 2][c];
                else
                    dp[(i + 1) % 2][c] = dp[i % 2][c] + dp[i % 2][c - nums[i]];
            }
        }
        return dp[n % 2][target];
    }
};