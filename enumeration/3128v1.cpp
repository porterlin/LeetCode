class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> row(m, vector<int>(n));
        vector<int> colSum(n);
        for (int i = 0; i < m; i++) {
            int sum = accumulate(grid[i].begin(), grid[i].end(), 0);
            for (int j = 0; j < n; j++) {
                row[i][j] = sum - grid[i][j];
                colSum[j] += grid[i][j];
            }
        }

        vector<vector<int>> col(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                col[i][j] = colSum[j] - grid[i][j];
            }
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ans += row[i][j] * col[i][j];
            }
        }
        return ans;
    }
};