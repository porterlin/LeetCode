class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        int leftSum;
        int rightSum;
        for (int i = 0; i < n; i++) {
            leftSum = prefixSum[i] - prefixSum[0];
            rightSum = prefixSum[n] - prefixSum[i + 1];
            if (leftSum == rightSum)
                return i;
        }
        return -1;
    }
};