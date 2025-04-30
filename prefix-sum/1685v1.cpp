class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int q = nums[i];
            int j = ranges::lower_bound(nums, q) - nums.begin();
            int left = q * j - prefixSum[j];
            int right = prefixSum[n] - prefixSum[j] - q * (n - j);
            result[i] = left + right;
        }
        return result;
    }
};