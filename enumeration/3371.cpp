class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n = nums.size(), ans = INT_MIN;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        unordered_map<int, int> mp;
        for (auto& num : nums)
            mp[num]++;
        for (int i = 0; i < n; i++) {
            if ((sum - nums[i]) % 2 != 0)
                continue;
            int val = (sum - nums[i]) / 2;
            if (mp.contains(val) && (val != nums[i] || mp[val] > 1))
                ans = max(ans, nums[i]);
        }
        return ans;
    }
};