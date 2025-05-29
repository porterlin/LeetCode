class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size(), ans = 0;
        int check[26];
        ranges::fill(check, INT_MIN);
        for (int i = 0; i < chars.size(); i++)
            check[chars[i] - 'a'] = vals[i];

        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++) {
            int curScore = s[i] - 'a' + 1;
            if (check[s[i] - 'a'] != INT_MIN)
                curScore = check[s[i] - 'a'];

            dp[i + 1] = max(dp[i], 0) + curScore;
            ans = max(ans, dp[i + 1]);
        }
        return ans;
    }
};