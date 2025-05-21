class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
            }
        }

        auto check = [&](int side) -> bool {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (j + 1 - side < 0 || i + 1 - side < 0)
                        continue;
                    int val = sum[i + 1][j + 1] - sum[i + 1][j + 1 - side] - sum[i + 1 - side][j + 1] + sum[i + 1 - side][j + 1 - side];
                    if (val <= threshold)
                        return true;
                }
            }
            return false;
        };

        int left = 1, right = min(m, n);
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (check(mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right;
    }
};