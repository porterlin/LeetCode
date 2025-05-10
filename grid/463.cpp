class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 0)
                return 0;
            if (grid[i][j] == 2)
                return 1;

            grid[i][j] = 2;

            int up = dfs(i - 1, j);
            int left = dfs(i, j - 1);
            int down = dfs(i + 1, j);
            int right = dfs(i, j + 1);

            ans += (4 - up - left - down - right);
            return 1;
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dfs(i, j);
                    return ans;
                }
            }
        }
        return 0;
    }
};