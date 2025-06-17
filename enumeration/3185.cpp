class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        long long ans = 0;
        int cnt[24]{};
        for (auto& h : hours) {
            ans += cnt[(24 - h % 24) % 24];
            cnt[h % 24]++;
        }
        return ans;
    }
};