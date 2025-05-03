class Solution {
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for (int i = 0; (n >> i) > 0; i++)
            if (((n >> i) & 1) == 1)
                powers.push_back(i);
        
        vector<long long> prefix(powers.size() + 1);
        prefix[0] = 1;
        for (int i = 0; i < powers.size(); i++)
            prefix[i + 1] = prefix[i] + powers[i];
        
        vector<int> ans(queries.size());
        const int MOD = 1e9 + 7;
        for (int i = 0; i < queries.size(); i++) {
            int exp = prefix[queries[i][1] + 1] - prefix[queries[i][0]];
            int buf = 1;
            while (exp > 0) {
                buf = (buf * 2) % MOD;
                exp--;
            }
            ans[i] = buf;
        }
        return ans;
    }
};