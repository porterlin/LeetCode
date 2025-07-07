class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<vector<string>> memo(10, vector<string>(target + 1, "@"));
        auto cmp = [](string a, string b) -> bool {
            if (a.size() != b.size())
                return a.size() > b.size();

            for (int i = 0; i < a.size(); i++) {
                if (a[i] == b[i])
                    continue;
                return a[i] > b[i];
            }
            return true;
        };
        auto dfs = [&](this auto&& dfs, int i, int c) -> string {
            if (i > 9)
                return c == 0 ? "" : "!";
            if (memo[i][c] != "@")
                return memo[i][c];
            if (cost[i - 1] > c)
                return memo[i][c] = dfs(i + 1, c);

            string a = dfs(i + 1, c);
            string b = dfs(i, c - cost[i - 1]) + to_string(i);
            if (a[0] == '!' && b[0] == '!')
                return memo[i][c] = "!";
            else if (a[0] == '!')
                return memo[i][c] = b;
            else if (b[0] == '!')
                return memo[i][c] = a;
            else
                return memo[i][c] = cmp(a, b) ? a : b;
        };

        string ans = dfs(1, target);
        return ans[0] == '!' ? "0" : ans;
    }
};