class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        ranges::sort(nums, greater<>());
        int ans = 0;
        for (int i = 0; i < nums.size(); i += 2)
            ans += min(nums[i], nums[i + 1]);

        return ans;
    }
};