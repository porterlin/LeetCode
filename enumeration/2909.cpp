class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> suf(nums.size());
        suf[nums.size() - 1] = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
            suf[i] = min(suf[i + 1], nums[i]);
        
        int pre = nums[0];
        int ans = INT_MAX;
        for (int i = 1; i < nums.size() - 1; i++) {
            if (nums[i] > pre && nums[i] > suf[i + 1])
                ans = min(ans, nums[i] + pre + suf[i + 1]);
            pre = min(pre, nums[i]);
        }
        return ans != INT_MAX ? ans : -1;
    }
};