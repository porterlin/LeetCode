class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1e9);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int c = target; c >= nums[i]; c--) {
                dp[c] = max(dp[c], dp[c - nums[i]] + 1);
            }
        }
        return dp[target] <= 0 ? -1 : dp[target];
    }
};