class Solution {
public:
    int largestArea(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<pair<int, int>> buf;
        int cnt = 0;
        auto dfs = [&](this auto&& dfs, int i, int j, char target) -> bool {
            if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
                return grid[i][j] != target && grid[i][j] != '0';

            if (grid[i][j] != target && grid[i][j] != '0')
                return true;
            if (grid[i][j] == '0')
                return false;

            grid[i][j] = '#';
            buf.push_back({i, j});
            cnt++;
            
            return dfs(i - 1, j, target) && dfs(i, j - 1, target) && dfs(i + 1, j, target) && dfs(i, j + 1, target);
        };

        int ans = 0;
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] != '0' && grid[i][j] != '#') {
                    char target = grid[i][j];
                    cnt = 0;
                    buf.clear();
                    if (dfs(i, j, target))
                        ans = max(ans, cnt);
                    else {
                        for (auto [a, b] : buf)
                            grid[a][b] = target;
                    }
                }
            }
        }
        return ans;
    }
};