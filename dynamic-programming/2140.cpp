class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // dp[i] = max(dp[i - 1], dp[i - questions[i][1] - 1] + questions[i][0])
        // dp[i + 1] = max(dp[i], dp[i - questions[i][1]] + questions[i][0])
        int n = questions.size();
        ranges::reverse(questions);
        vector<long long> dp(n + 1);

        for (int i = 0; i < n; i++) {
            long long a = dp[i];
            long long b = 0;
            if (i - questions[i][1] >= 0)
                b = dp[i - questions[i][1]];
            dp[i + 1] = max(a, b + questions[i][0]);
        }

        return dp[n];
    }
};