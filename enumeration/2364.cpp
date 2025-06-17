class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(n);
        for (int i = 0; i < n; i++) {
            diff[i] = nums[i] - i;
        }

        long long equalPair = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            if (mp.contains(diff[i]))
                equalPair += mp[diff[i]];
            mp[diff[i]]++;
        }
        return 1LL * n * (n - 1) / 2 - equalPair;
    }
};