class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        int cnt[60]{};
        for (int i = 0; i < time.size(); i++) {
            ans += cnt[(60 - time[i] % 60) % 60]; // 用這樣寫可以同時處理餘 0 和不餘 0 的情況
            cnt[time[i] % 60]++;
        }
        return ans;
    }
};