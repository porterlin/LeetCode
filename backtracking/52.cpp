class Solution {
public:
    int totalNQueens(int n) {
        int ans = 0;
        vector<int> valid(n), diag1(2 * n - 1), diag2(2 * n - 1);
        auto dfs = [&](this auto&& dfs, int r) {
            if (r == n) {
                ans++;
                return;
            }

            for (int c = 0; c < n; c++) {
                int rc = r - c + n - 1;
                if (!valid[c] && !diag1[r + c] && !diag2[rc]) {
                    valid[c] = diag1[r + c] = diag2[rc] = true;
                    dfs(r + 1);
                    valid[c] = diag1[r + c] = diag2[rc] = false;
                }
            }
        };

        dfs(0);
        return ans;
    }
};