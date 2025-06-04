class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int ans = -1, n = grid.size();
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, -1, 0, 1};

        queue<pair<int, int>> land;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1)
                    land.push({i, j});
            }
        }

        if (land.size() == 0 || land.size() == n * n)
            return -1;

        while (!land.empty()) {
            ans++;
            int landsize = land.size();
            for (int i = 0; i < landsize; i++) {
                auto [x, y] = land.front();
                land.pop();
                for (int j = 0; j < 4; j++) {
                    int nx = x + dx[j];
                    int ny = y + dy[j];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = 1;
                        land.push({nx, ny});
                    }
                }
            }
        }

        return ans;
    }
};