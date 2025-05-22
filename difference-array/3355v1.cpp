class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> d(n + 1);
        d[0] = nums[0];
        for (int i = 1; i < n; i++)
            d[i] = nums[i] - nums[i - 1];
        d[n] -= nums[n - 1];

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            d[l]--;
            d[r + 1]++;
        }

        int sum = 0;
        for (auto& val : d) {
            sum += val;
            if (sum > 0)
                return false;
        }
        return true;
    }
};