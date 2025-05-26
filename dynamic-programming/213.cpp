class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        auto rob1 = [&](int start, int end) -> int {
            int f1 = 0, f0 = 0, new_f;
            for (int i = start; i < end; i++) {
                new_f = max(f1, f0 + nums[i]);
                f0 = f1;
                f1 = new_f;
            }
            return f1;
        };
        return max(nums[0] + rob1(2, n - 1), rob1(1, n));
    }
};