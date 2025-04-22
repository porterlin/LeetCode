class Solution {
public:
    int subarraySum(vector<int>& nums) {
        vector<int> prefixSum(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int start = max(0, i - nums[i]);
            int end = i;
            ans += prefixSum[end + 1] - prefixSum[start];
        }
        return ans;
    }
};