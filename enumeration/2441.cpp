class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> st;
        int ans = -1e9;
        for (int i = 0; i < nums.size(); i++) {
            if (abs(nums[i]) > ans && st.count(-nums[i]))
                ans = abs(nums[i]);
            st.insert(nums[i]);
        }
        return ans == -1e9 ? -1 : ans;
    }
};