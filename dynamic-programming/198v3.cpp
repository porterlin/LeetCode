// 遞推 + 空間優化
// time complexity: O(n)
// space complexity: O(1)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int f0 = 0, f1 = 0, new_f;
        for (int i = 0; i < n; i++) {
            new_f = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};