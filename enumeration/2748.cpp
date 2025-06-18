class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int ans = 0;
        int cnt[10]{};
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j < 10; j++) {
                if (gcd(nums[i] % 10, j) == 1)
                    ans += cnt[j];
            }
            int x = nums[i];
            while (x >= 10) {
                x /= 10;
            }
            cnt[x]++;
        }
        return ans;
    }
};