// dp 可以用一個變數表示
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int n = s.size(), ans = 0;
        int check[26];
        iota(check, check + 26, 1);
        for (int i = 0; i < chars.size(); i++)
            check[chars[i] - 'a'] = vals[i];

        int f = 0;
        for (int i = 0; i < n; i++) {
            f = max(f, 0) + check[s[i] - 'a'];
            ans = max(ans, f);
        }
        return ans;
    }
};