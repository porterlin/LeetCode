class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        int cnt;

        auto dfs = [&](this auto&& dfs, int i, int j) -> void {
            if (i < 0 || j < 0 || i == m || j == n || grid[i][j] != 1)
                return;
            
            grid[i][j] = 2;
            cnt++;

            dfs(i - 1, j);
            dfs(i, j - 1);
            dfs(i + 1, j);
            dfs(i, j + 1);
        };

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cnt = 0;
                    dfs(i, j);
                    ans = max(ans, cnt);
                }
            }
        }

        return ans;
    }
};