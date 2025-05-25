class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> cache(n + 1, -1);
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i < 2)
                return 0;
            if (cache[i] != -1)
                return cache[i];
            
            int res = min(dfs(i - 1) + cost[i - 1], dfs(i - 2) + cost[i - 2]);
            cache[i] = res;
            return res;
        };
        return dfs(n);
    }
};