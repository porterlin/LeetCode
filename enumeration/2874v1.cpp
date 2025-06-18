class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = -1e18;
        vector<int> buf(nums.size());
        int mx = nums[0], mn = nums[0];
        for (int i = 1; i < buf.size(); i++) {
            buf[i] = max(buf[i - 1], mx - mn);

            if (nums[i] > mx) {
                mx = nums[i];
                mn = nums[i];
                continue;
            }
            mn = min(mn, nums[i]);
        }

        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, 1LL * buf[i] * nums[i]);
        }
        return ans;
    }
};