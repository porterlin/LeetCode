class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            dp[i][0] = 1;
        
        int ans = 0;
        bool check = false;
        for (int c = 1; c < n; c++) {
            for (int r = 0; r < m; r++) {
                if (r != 0 && grid[r][c] > grid[r - 1][c - 1] && dp[r - 1][c - 1] == 1) {
                    check = true;
                    dp[r][c] = 1;
                } else if (grid[r][c] > grid[r][c - 1] && dp[r][c - 1] == 1) {
                    check = true;
                    dp[r][c] = 1;
                } else if (r != m - 1 && grid[r][c] > grid[r + 1][c - 1] && dp[r + 1][c - 1] == 1) {
                    check = true;
                    dp[r][c] = 1;
                }
            }

            if (!check)
                return ans;
            check = false;
            ans++;
        }
        return ans;
    }
};