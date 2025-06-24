// 由於不是算方法數，而是判斷能不能，所以可以直接用 bool 判斷
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;
        
        sum /= 2;

        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(sum + 1, -1));
        auto dfs = [&](this auto&& dfs, int i, int c) -> bool {
            if (i < 0)
                return c == 0;
            if (memo[i][c] != -1)
                return memo[i][c];
            if (c < nums[i])
                return memo[i][c] = dfs(i - 1, c);

            return memo[i][c] = dfs(i - 1, c) || dfs(i - 1, c - nums[i]);
        };

        return dfs(n - 1, sum);
    }
};