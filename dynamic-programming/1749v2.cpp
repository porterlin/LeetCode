// dp 可以用一個變數表示
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), fmx = 0, fmn = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            fmx = max(fmx, 0) + nums[i];
            fmn = min(fmn, 0) + nums[i];
            ans = max(ans, max(fmx, -fmn));
        }
        return ans;
    }
};