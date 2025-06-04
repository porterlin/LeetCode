class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int cnt = 0;
        vector<vector<int>> ans(m, vector<int>(n));
        vector<pair<int, int>> dxy = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

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
                    if (mat[nx][ny] == 1) {
                        mat[nx][ny] = 0;
                        ans[nx][ny] = cnt;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return ans;
    }
};