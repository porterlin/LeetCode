class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int m = land.size(), n = land[0].size();
        auto dfs = [&](this auto&& dfs, int i, int j) -> int {
            if (i < 0 || j < 0 || i == m || j == n || land[i][j] != 0)
                return 0;
            
            land[i][j] = -1;

            return 1 + dfs(i - 1, j) + dfs(i - 1, j - 1) + dfs(i, j - 1) + dfs(i + 1, j - 1) + dfs(i + 1, j) + dfs(i + 1, j + 1) + dfs(i, j + 1) + dfs(i - 1, j + 1);
        };

        vector<int> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 0) {
                    int cnt = dfs(i, j);
                    ans.push_back(cnt);
                }
            }
        }
        ranges::sort(ans);
        return ans;
    }
};