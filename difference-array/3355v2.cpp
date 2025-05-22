class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size() + 1);
        for (auto& q : queries) {
            int l = q[0], r = q[1];
            diff[l]++;
            diff[r + 1]--;
        }

        int sum_dec = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum_dec += diff[i];
            if (nums[i] > sum_dec)
                return false;
        }
        return true;
    }
};