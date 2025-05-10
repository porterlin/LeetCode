class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        auto dfs = [&](this auto&& dfs, int i, int j, int last) -> int {
            if (i < 0 || i == m || j == n || grid[i][j] <= last || vis[i][j] == 1)
                return -1;

            vis[i][j] = 1;
            
            int a = dfs(i - 1, j + 1, grid[i][j]);
            int b = dfs(i, j + 1, grid[i][j]);
            int c = dfs(i + 1, j + 1, grid[i][j]);

            return 1 + max(a, max(b, c));
        };

        int ans = 0;
        for (int i = 0; i < m; i++)
            ans = max(ans, dfs(i, 0, 0));
        
        return ans;
    }
};