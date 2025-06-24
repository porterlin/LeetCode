class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(target + 1, -1));

        auto dfs = [&](this auto&& dfs, int i, int c) -> int {
            if (i < 0)
                return c == 0 ? 0 : -1e9;
            if (memo[i][c] != -1)
                return memo[i][c];
            if (c < nums[i])
                return memo[i][c] = dfs(i - 1, c);
            
            return memo[i][c] = max(dfs(i - 1, c), dfs(i - 1, c - nums[i]) + 1);
        };
        
        int ans = dfs(n - 1, target);
        return ans <= 0 ? -1 : ans;
    }
};