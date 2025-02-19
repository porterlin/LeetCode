// time complexity: O(N)
// space complexity: O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> pre_max(height.size());
        vector<int> suf_max(height.size());
        int ans = 0;
        pre_max[0] = height[0];
        suf_max[height.size() - 1] = height[height.size() - 1];
        for (int i = 1; i < pre_max.size(); i++) {
            pre_max[i] = max(pre_max[i - 1], height[i]);
        }
        for (int i = height.size() - 2; i >= 0; i--) {
            suf_max[i] = max(suf_max[i + 1], height[i]);
        }

        for (int i = 0; i < height.size(); i++) {
            ans += (min(suf_max[i], pre_max[i]) - height[i]);
        }

        return ans;
    }
};