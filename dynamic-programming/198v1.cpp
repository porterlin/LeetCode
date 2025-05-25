// 記憶化搜索
// time complexity: O(n)
// space complexity: O(n)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> cache(n, -1);
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i < 0)
                return 0;
            if (cache[i] != -1)
                return cache[i];

            int money = max(dfs(i - 1), dfs(i - 2) + nums[i]);
            cache[i] = money;
            
            return money;
        };
        return dfs(n - 1);
    }
};