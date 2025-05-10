class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < 0 || j < 0 || i == m || j == n || grid[i][j] <= 0)
                return 0;

            int val = grid[i][j];
            grid[i][j] = -1;

            return val + dfs(i - 1, j) + dfs(i, j - 1) + dfs(i + 1, j) + dfs(i, j + 1);
        };

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0)
                    ans = max(ans, dfs(i, j));
            }
        }

        return ans;
    }
};