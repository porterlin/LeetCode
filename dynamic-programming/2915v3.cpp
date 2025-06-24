class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(target + 1, -1e9));
        dp[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= target; c++) {
                if (c < nums[i])
                    dp[(i + 1) % 2][c] = dp[i % 2][c];
                else
                    dp[(i + 1) % 2][c] = max(dp[i % 2][c], dp[i % 2][c - nums[i]] + 1);
            }
        }
        return dp[n % 2][target] <= 0 ? -1 : dp[n % 2][target];
    }
};