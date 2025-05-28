class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> memo(target + 1, -1);
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i < 0)
                return 0;
            if (i == 0)
                return 1;
            if (memo[i] != -1)
                return memo[i];

            int cnt = 0;
            for (auto& num : nums)
                cnt += dfs(i - num);
            
            return memo[i] = cnt;
        };
        return dfs(target);
    }
};