class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans;
        vector<pair<int, int>> dxy = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});

        if (grid[start[0]][start[1]] > 1 && grid[start[0]][start[1]] >= pricing[0] && grid[start[0]][start[1]] <= pricing[1]) {
            ans.push_back({start[0], start[1]});
            grid[start[0]][start[1]] = 0;
        }

        while (!q.empty()) {
            int qsize = q.size();
            vector<tuple<int, int, int>> buf;
            for (int i = 0; i < qsize; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (auto& [dx, dy] : dxy) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;
                    if (grid[nx][ny] > 1 && grid[nx][ny] >= pricing[0] && grid[nx][ny] <= pricing[1])
                        buf.push_back({nx, ny, grid[nx][ny]});
                    if (grid[nx][ny] != 0) {
                        grid[nx][ny] = 0;
                        q.push({nx, ny});
                    }
                }
            }

            ranges::sort(buf, [](auto a, auto b) {
                auto [ax, ay, aval] = a;
                auto [bx, by, bval] = b;

                if (aval != bval)
                    return aval < bval;                
                if (ax != bx)
                    return ax < bx;                
                if (ay != by)
                    return ay < by;
                return aval < bval;
            });

            for (auto& [x, y, _] : buf) {
                if (ans.size() == k)
                    return ans;
                ans.push_back({x, y});
            }
        }

        return ans;
    }
};