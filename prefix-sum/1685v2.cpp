class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1);
        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        vector<int> result(n);
        for (int i = 0; i < n; i++) {
            int left = abs(prefixSum[i] - nums[i] * i);
            int right = abs(prefixSum[n] - prefixSum[i] - nums[i] * (n - i));
            result[i] = left + right;
        }
        return result;
    }
};