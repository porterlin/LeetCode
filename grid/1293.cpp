class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        if (m == 1 && n == 1)
            return 0;
        k = min(k, m + n - 3); // 優化
        vector<pair<int, int>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector vis(m, vector(n, vector<bool>(k + 1)));
        queue<array<int, 3>> q;
        q.push({0, 0, k});
        while (!q.empty()) {
            ans++;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto [x, y, curK] = q.front();
                q.pop();
                for (auto& [dx, dy] : dxy) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;
                    if (nx == m - 1 && ny == n - 1)
                        return ans;
                    if (grid[nx][ny] == 0 && !vis[nx][ny][curK]) {
                        vis[nx][ny][curK] = 1;
                        q.push({nx, ny, curK});
                    } else if (grid[nx][ny] == 1 && curK > 0 && !vis[nx][ny][curK]) {
                        vis[nx][ny][curK] = 1;
                        q.push({nx, ny, curK - 1});
                    }
                }
            }
        }
        return -1;
    }
};