class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if (q.empty())
            return fresh == 0 ? 0 : -1;

        int ans = -1;
        while (!q.empty()) {
            ans++;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& [dx, dy] : dxy) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;
                    if (grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return fresh == 0 ? ans : -1;
    }
};