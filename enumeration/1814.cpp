class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        long long ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            string str = to_string(nums[i]);
            ranges::reverse(str);
            int rev = stoi(str);
            if (mp.contains(nums[i] - rev))
                ans = (ans + mp[nums[i] - rev]) % MOD;
            mp[nums[i] - rev]++;
        }
        return ans;
    }
};