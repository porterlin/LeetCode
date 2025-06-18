// 跟 v1 做法一樣，只是合併一些程式碼，把空間複雜度從 O(mn) 壓到 O(n)
class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> colSum(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                colSum[j] += grid[i][j];
            }
        }

        long long ans = 0;
        for (int i = 0; i < m; i++) {
            int rowSum = accumulate(grid[i].begin(), grid[i].end(), 0);
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    ans += (rowSum - 1) * (colSum[j] - 1);
            }
        }
        return ans;
    }
};