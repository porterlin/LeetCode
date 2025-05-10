class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int cnt = 0;
        
        auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
            if (i < 0 || j < 0 || i == m || j == n)
                return false;
            
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                return grid[i][j] != 1 && grid[i][j] != 2;

            if (grid[i][j] == 2 || grid[i][j] == 0)
                return true;

            grid[i][j] = 2;
            cnt++;

            bool up = dfs(i - 1, j);
            bool left = dfs(i, j - 1);
            bool down = dfs(i + 1, j);
            bool right = dfs(i, j + 1);

            if (up && left && down && right)
                return true;
            return false;
        };

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    cnt = 0;
                    if (dfs(i, j))
                        ans += cnt;
                }
            }
        }
        return ans;
    }
};