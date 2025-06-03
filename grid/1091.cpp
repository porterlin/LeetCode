class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1)
            return -1;
        if (grid.size() == 1 && grid[0].size() == 1)
            return 1;
        
        int ans = 1;
        queue<pair<int, int>> q;
        grid[0][0] = 1;
        q.push({0, 0});
        while (!q.empty()) {
            ans++;
            int qsize = q.size();
            for (int k = 0; k < qsize; k++) {
                auto [r, c] = q.front();
                q.pop();
                for (int i = r - 1; i <= r + 1; i++) {
                    for (int j = c - 1; j <= c + 1; j++) {
                        if (i < 0 || j < 0 || i >= m || j >= n)
                            continue;
                        if (i == m - 1 && j == n - 1)
                            return ans;
                        if (grid[i][j] == 0) {
                            grid[i][j] = 1;
                            q.push({i, j});
                        }
                    }
                }
            }
        }
        return -1;
    }
};