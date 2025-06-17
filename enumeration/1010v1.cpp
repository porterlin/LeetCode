class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        int cnt[60]{};
        for (int i = 0; i < time.size(); i++) {
            if (time[i] % 60 != 0)
                ans += cnt[60 - time[i] % 60];
            else
                ans += cnt[0];

            cnt[time[i] % 60]++;
        }
        return ans;
    }
};