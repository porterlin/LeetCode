// 硬算統計和等於 sum 的個數，要 unsigned long long 才不會爆
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        
        sum /= 2;

        int n = nums.size();
        vector<vector<unsigned long long>> memo(n, vector<unsigned long long>(sum + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int c) -> unsigned long long {
            if (i < 0)
                return c == 0;
            if (memo[i][c] != -1)
                return memo[i][c];
            if (c < nums[i])
                return memo[i][c] = dfs(i - 1, c);

            return memo[i][c] = dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
        };

        return dfs(n - 1, sum) > 0;
    }
};