class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];

        int r1, c1, r2, c2;
        vector<vector<int>> ans(m, vector<int>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                r1 = i - k < 0 ? 0 : i - k;
                c1 = j - k < 0 ? 0 : j - k;
                r2 = i + k >= m ? m - 1 : i + k;
                c2 = j + k >= n ? n - 1 : j + k;
                ans[i][j] = sum[r2 + 1][c2 + 1] - sum[r2 + 1][c1] - sum[r1][c2 + 1] + sum[r1][c1];
            }
        }
        return ans;
    }
};