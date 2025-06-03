class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int ans = 0, m = maze.size(), n = maze[0].size();
        bool vis[100][100]{};
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        vis[entrance[0]][entrance[1]] = 1;

        while (!q.empty()) {
            ans++;
            int qsize = q.size();
            for (int k = 0; k < qsize; k++) {
                auto [r, c] = q.front();
                q.pop();

                for (int i = r - 1; i <= r + 1; i++) {
                    for (int j = c - 1; j <= c + 1; j++) {
                        if ((i != r && j != c) || (i == r && j == c) || i < 0 || j < 0 || i >= m || j >= n)
                            continue;
                        if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && maze[i][j] == '.' && vis[i][j] == 0)
                            return ans;
                        if (maze[i][j] == '.' && vis[i][j] == 0) {
                            q.push({i, j});
                            vis[i][j] = 1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};