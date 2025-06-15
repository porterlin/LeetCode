class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.contains(k - nums[i]) && mp[k - nums[i]] > 0) {
                ans++;
                mp[k - nums[i]]--;
                continue;
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};