// 從上到下
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size(), n = triangle[m - 1].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++)
            for (int j = 0; j <= n; j++)
                dp[i][j] = INT_MAX;
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (j > triangle[i - 1].size())
                    break;
                dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i - 1][j - 1];
            }
        }
        return ranges::min(dp[m]);
    }
};