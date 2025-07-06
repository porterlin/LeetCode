class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        ranges::sort(rewardValues, greater<>());
        vector<vector<int>> memo(n, vector<int>(1e4, -1));
        auto dfs = [&](this auto&& dfs, int i, int c) -> int {
            if (i < 0)
                return c;
            if (memo[i][c] != -1)
                return memo[i][c];
            if (rewardValues[i] <= c)
                return memo[i][c] = dfs(i - 1, c);
            
            return memo[i][c] = max(dfs(i - 1, c), dfs(i - 1, c + rewardValues[i]));
        };
        return dfs(n - 1, 0);
    }
};