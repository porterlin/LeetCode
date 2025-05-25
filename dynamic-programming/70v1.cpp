class Solution {
public:
    int climbStairs(int n) {
        vector<int> cache(n + 1, -1);
        auto dfs = [&](this auto&& dfs, int i) -> int {
            if (i <= 1)
                return 1;
            if (cache[i] != -1)
                return cache[i];
            
            int cnt = dfs(i - 1) + dfs(i - 2);
            cache[i] = cnt;
            return cnt;
        };
        return dfs(n);
    }
};