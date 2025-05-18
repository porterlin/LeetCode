class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<bool> valid(n), diag1(2 * n - 1), diag2(2 * n - 1);
        auto dfs = [&](this auto&& dfs, int r) {
            if (r == n) {
                ans.push_back(board);
                return;
            }

            for (int c = 0; c < n; c++) {
                int rc = r - c + n - 1;
                if (!valid[c] && !diag1[r + c] && !diag2[rc]) {
                    valid[c] = diag1[r + c] = diag2[rc] = true;
                    board[r][c] = 'Q';
                    dfs(r + 1);
                    board[r][c] = '.';
                    valid[c] = diag1[r + c] = diag2[rc] = false;
                }
            }
        };

        dfs(0);
        return ans;
    }
};