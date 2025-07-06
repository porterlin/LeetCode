class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<array<int, 2>> vec(strs.size());
        for (int i = 0; i < strs.size(); i++) {
            int cnt0 = 0, cnt1 = 0;
            for (auto& c : strs[i]) {
                if (c == '1')
                    cnt1++;
                else
                    cnt0++;
            }
            vec[i] = {cnt0, cnt1};
        }

        int memo[strs.size()][m + 1][n + 1];
        memset(memo, -1, sizeof(memo));
        auto dfs = [&](this auto&& dfs, int i, int zeros, int ones) -> int {
            if (i < 0)
                return 0;
            if (memo[i][zeros][ones] != -1)
                return memo[i][zeros][ones];
            int curZeros = vec[i][0];
            int curOnes = vec[i][1];
            if (zeros + curZeros > m || ones + curOnes > n)
                return memo[i][zeros][ones] = dfs(i - 1, zeros, ones);
            
            return memo[i][zeros][ones] = max(dfs(i - 1, zeros, ones), dfs(i - 1, zeros + curZeros, ones + curOnes) + 1);
        };
        return dfs(vec.size() - 1, 0, 0);
    }
};