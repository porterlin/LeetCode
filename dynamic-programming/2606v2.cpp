class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size(), ans = 0;
        int check[26];
        iota(check, check + 26, 1);
        for (int i = 0; i < chars.size(); i++)
            check[chars[i] - 'a'] = vals[i];

        vector<int> dp(n + 1);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i], 0) + check[s[i] - 'a'];
            ans = max(ans, dp[i + 1]);
        }
        return ans;
    }
};