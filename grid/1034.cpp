class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int m = grid.size(), n = grid[0].size();
        int target = grid[row][col];
        vector<vector<int>> ans = grid;

        auto dfs = [&](this auto&& dfs, int i, int j) -> bool {
            if (i < 0 || j < 0 || i == m || j == n || (grid[i][j] != -1 && grid[i][j] != target))
                return false;
            if (grid[i][j] == -1)
                return true;
            
            grid[i][j] = -1;

            bool up = dfs(i - 1, j);
            bool left = dfs(i, j - 1);
            bool down = dfs(i + 1, j);
            bool right = dfs(i, j + 1);

            if (!up || !left || !down || !right)
                ans[i][j] = color;
            
            return true;
        };

        dfs(row, col);
        return ans;
    }
};