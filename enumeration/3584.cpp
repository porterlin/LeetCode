class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long mn = 1e9, mx = -1e9, ans = -1e18;
        for (int i = m - 1; i < nums.size(); i++) {
            mn = min(mn, (long long)nums[i - m + 1]);
            mx = max(mx, (long long)nums[i - m + 1]);
            ans = max({ans, mn * nums[i], mx * nums[i]});
        }
        return ans;
    }
};