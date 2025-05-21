class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> x(m + 1, vector<int>(n + 1));
        vector<vector<int>> y(m + 1, vector<int>(n + 1));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                x[i + 1][j + 1] = x[i + 1][j] + x[i][j + 1] - x[i][j];
                y[i + 1][j + 1] = y[i + 1][j] + y[i][j + 1] - y[i][j];
                if (grid[i][j] == 'X')
                    x[i + 1][j + 1]++;
                else if (grid[i][j] == 'Y')
                    y[i + 1][j + 1]++;
       
                if (x[i + 1][j + 1] > 0 && x[i + 1][j + 1] == y[i + 1][j + 1])
                    ans++;
            }
        }
        return ans;
    }
};