class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int> prefixSum(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        unordered_map<int, int> hash;
        int ans = 0;
        for (int i = 0; i < prefixSum.size(); i++) {
            if (hash.find(prefixSum[i] - goal) != hash.end())
                ans += hash[prefixSum[i] - goal];
            hash[prefixSum[i]]++;
        }
        return ans;
    }
};