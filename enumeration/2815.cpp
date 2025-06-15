class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> candidate(n);
        for (int i = 0; i < n; i++) {
            string str = to_string(nums[i]);
            for (auto& c : str) {
                if (c - '0' > candidate[i])
                    candidate[i] = c - '0';
            }
        }

        int ans = -1;
        unordered_map<int, priority_queue<int>> mp;
        for (int i = 0; i < n; i++) {
            if (mp.contains(candidate[i])) {
                ans = max(ans, mp[candidate[i]].top() + nums[i]);
            }
            mp[candidate[i]].push(nums[i]);
        }
        return ans;
    }
};