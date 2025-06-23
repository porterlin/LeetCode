// 再優化到只需要一維陣列
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2)
            return 0;
        target /= 2;

        int n = nums.size();
        vector<int> dp(target + 1);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = target; c >= nums[i]; c--) {
                dp[c] = dp[c] + dp[c - nums[i]];
            }
        }
        return dp[target];
    }
};