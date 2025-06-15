class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, priority_queue<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            int sum = 0;
            string str = to_string(nums[i]);
            for (auto& c : str)
                sum += c - '0';
            
            if (mp.count(sum))
                ans = max(ans, nums[i] + mp[sum].top());
            mp[sum].push(nums[i]);
        }
        return ans;
    }
};