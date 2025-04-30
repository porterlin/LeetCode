class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        long long n = nums.size();
        unordered_map<long long, vector<long long>> hash;
        unordered_map<long long, vector<long long>> prefixSum;
        for (int i = 0; i < n; i++) {
            hash[nums[i]].push_back(i);
            if (prefixSum[nums[i]].empty())
                prefixSum[nums[i]].push_back(0);
            
            long long preSize = prefixSum[nums[i]].size();
            prefixSum[nums[i]].push_back(i + prefixSum[nums[i]][preSize - 1]);
        }

        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            long long q = nums[i];
            if (hash[q].size() == 1) {
                arr[i] = 0;
                continue;
            }
            long long j = ranges::lower_bound(hash[q], i) - hash[q].begin();
            long long left = i * j - prefixSum[q][j];
            long long right = prefixSum[q][prefixSum[q].size() - 1] - prefixSum[q][j] - i * (prefixSum[q].size() - 1 - j);
            arr[i] = left + right;
        }
        return arr;
    }
};