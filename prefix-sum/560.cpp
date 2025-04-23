class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        unordered_map<int, int> hash;
        int ans = 0;
        for (int i = 0; i < prefixSum.size(); i++) {
            if (hash.find(prefixSum[i] - k) != hash.end())
                ans += hash[prefixSum[i] - k];
            hash[prefixSum[i]]++;
        }
        return ans;
    }
};