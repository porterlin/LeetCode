class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mp;
        for (auto& p : power)
            mp[p]++;
        
        vector<pair<int, int>> a(mp.begin(), mp.end());
        ranges::sort(a);

        vector<long long> memo(a.size(), -1);
        auto dfs = [&](this auto&& dfs, int i) -> long long {
            if (i < 0)
                return 0;
            if (memo[i] != -1)
                return memo[i];

            int j = i;
            while (j > 0 && a[j - 1].first >= a[i].first - 2)
                j--;

            return memo[i] = max(dfs(i - 1), dfs(j - 1) + 1LL * a[i].first * a[i].second);
        };

        return dfs(a.size() - 1);
    }
};