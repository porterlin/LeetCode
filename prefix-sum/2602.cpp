class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        ranges::sort(nums);

        vector<long long> prefixSum(n + 1);
        for (int i = 0; i < nums.size(); i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        vector<long long> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            long long q = queries[i];
            long long j = ranges::lower_bound(nums, q) - nums.begin();
            long long left = q * j - prefixSum[j];
            long long right = prefixSum[n] - prefixSum[j] - q * (n - j);
            ans[i] = left + right;
        }
        return ans;
    }
};