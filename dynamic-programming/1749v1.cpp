class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), mx = 0, mn = 0;
        vector<int> dpMax(n + 1);
        vector<int> dpMin(n + 1);
        for (int i = 0; i < n; i++) {
            dpMax[i + 1] = max(dpMax[i], 0) + nums[i];
            dpMin[i + 1] = min(dpMin[i], 0) + nums[i];
            mx = max(mx, dpMax[i + 1]);
            mn = min(mn, dpMin[i + 1]);
        }
        return max(mx, -mn);
    }
};