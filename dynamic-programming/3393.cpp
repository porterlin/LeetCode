class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        const int MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        int mx = 0;
        for (int i = 0; i < m; i++)
            mx = max(mx, ranges::max(grid[i]));

        int size = 1 << bit_width((unsigned) mx);
        if (k > size)
            return 0;
        
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(size, -1)));
        auto dfs = [&](this auto&& dfs, int i, int j, int x) -> int {
            if (i < 0 || j < 0)
                return 0;
            if (i == 0 && j == 0)
                return grid[i][j] == x;
            if (memo[i][j][x] != -1)
                return memo[i][j][x];

            return memo[i][j][x] = (dfs(i - 1, j, x ^ grid[i][j]) + dfs(i, j - 1, x ^ grid[i][j])) % MOD;
        };
        return dfs(m - 1, n - 1, k);
    }
};