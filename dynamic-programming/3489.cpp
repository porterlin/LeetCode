class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int memo[1000][10][1001];
        memset(memo, -1, sizeof(memo));

        auto dfs = [&](this auto&& dfs, int i, int ti, int t) -> int {
            if (i >= queries.size())
                return t == 0 ? i : INT_MAX;
            if (t == 0)
                return i;
            if (memo[i][ti][t] != -1)
                return memo[i][ti][t];
            if (ti < queries[i][0] || ti > queries[i][1] || t - queries[i][2] < 0)
                return memo[i][ti][t] = dfs(i + 1, ti, t);
            
            return memo[i][ti][t] = min(dfs(i + 1, ti, t), dfs(i + 1, ti, t - queries[i][2]));
        };

        for (int i = 0; i < n; i++) {
            nums[i] = dfs(0, i, nums[i]);
        }
        int mx = ranges::max(nums);
        return mx == INT_MAX ? -1 : mx;
    }
};