class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, int> mp;
        for (auto& p : power)
            mp[p]++;
        
        vector<pair<int, int>> a(mp.begin(), mp.end());
        ranges::sort(a);

        int n = a.size();
        vector<long long> dp(n + 1);
        for (int i = 0, j = 0; i < n; i++) {
            auto& [key, val] = a[i];

            while (a[j].first < key - 2)
                j++;

            dp[i + 1] = max(dp[i], dp[j] + (long long) key * val);
        }
        return dp[n];
    }
};