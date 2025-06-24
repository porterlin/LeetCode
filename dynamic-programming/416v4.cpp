class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        
        sum /= 2;

        int n = nums.size();
        vector<vector<int>> dp(2, vector<int>(sum + 1));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= sum; c++) {
                if (c < nums[i])
                    dp[(i + 1) % 2][c] = dp[i % 2][c];
                else
                    dp[(i + 1) % 2][c] = dp[i % 2][c] || dp[i % 2][c - nums[i]];
            }
        }
        return dp[n % 2][sum];
    }
};