class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            if (mp.contains(target - nums[i]) && mp[target - nums[i]] > 0) {
                mp[target - nums[i]]--;
                ans.push_back({nums[i], target - nums[i]});
                continue;
            }
            mp[nums[i]]++;
        }
        return ans;
    }
};