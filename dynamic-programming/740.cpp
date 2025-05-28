class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = ranges::max(nums);
        vector<int> a(mx + 1);
        for (auto& num : nums)
            a[num] += num;
        
        int f1 = 0, f0 = 0, new_f;
        for (int i = 0; i < mx + 1; i++) {
            new_f = max(f1, f0 + a[i]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};