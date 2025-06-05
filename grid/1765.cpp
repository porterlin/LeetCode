class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size(), n = isWater[0].size();
        vector<pair<int, int>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        vector<vector<int>> ans(m, vector<int>(n));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        int cnt = 0;
        while (!q.empty()) {
            cnt++;
            int qsize = q.size();
            for (int i = 0; i < qsize; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& [dx, dy] : dxy) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;
                    if (isWater[nx][ny] == 0) {
                        isWater[nx][ny] = 1;
                        ans[nx][ny] = cnt;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return ans;
    }
};