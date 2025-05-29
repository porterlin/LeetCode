class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i] = max(dp[i - 1], 0) + nums[i];
        // dp[i + 1] = max(dp[i], 0) + nums[i];
        int n = nums.size();
        int ans = INT_MIN;
        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i], 0) + nums[i];
            ans = max(ans, dp[i + 1]);
        }
        return ans;
    }
};