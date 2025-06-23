// 記憶化搜索
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2)
            return 0;
        target /= 2;

        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(target + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int c) -> int {
            if (i < 0)
                return c == 0;
            if (memo[i][c] != -1)
                return memo[i][c];
            if (c < nums[i])
                return memo[i][c] = dfs(i - 1, c);
            
            return memo[i][c] = dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
        };

        return dfs(n - 1, target);
    }
};