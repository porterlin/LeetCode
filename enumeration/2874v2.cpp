class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = -1e18;
        int maxDiff = 0, preMax = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, 1LL * maxDiff * nums[i]);
            maxDiff = max(maxDiff, preMax - nums[i]);
            preMax = max(preMax, nums[i]);
        }
        return ans;
    }
};