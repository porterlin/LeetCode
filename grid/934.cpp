class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<pair<int, int>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<pair<int, int>> q;
        int si = -1, sj = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    si = i;
                    sj = j;
                    break;
                }
            }
            if (si != -1)
                break;
        }

        auto dfs = [&](this auto&& dfs, int i, int j) {
            if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 0 || grid[i][j] == -1)
                return;
            
            grid[i][j] = -1;
            q.push({i, j});

            dfs(i - 1, j);
            dfs(i, j - 1);
            dfs(i + 1, j);
            dfs(i, j + 1);
        };
        dfs(si, sj);

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
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                        continue;
                    if (grid[nx][ny] == 0) {
                        grid[nx][ny] = -1;
                        q.push({nx, ny});
                    } else if (grid[nx][ny] == 1) {
                        return ans;
                    }
                }
            }
        }

        return ans;
    }
};