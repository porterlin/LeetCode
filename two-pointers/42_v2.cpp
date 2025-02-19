// time complexity: O(N)
// space complexity: O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int pre_max = 0, suf_max = 0;
        while (left < right) {
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            if (pre_max < suf_max) {
                ans += pre_max - height[left];
                left++;
            } else {
                ans += suf_max - height[right];
                right--;
            }
        }
        return ans;
    }
};