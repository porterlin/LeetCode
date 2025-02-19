class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        int left = 0, right = 0;
        int count = 0;
        while (right < nums.size()) {
            if (nums[right] == 1) {
                ans = max(ans, right - left + 1);
                right++;
            } else {
                if (count < k) {
                    count++;
                    ans = max(ans, right - left + 1);
                    right++;
                } else {
                    while (count >= k) {
                        left++;
                        if (nums[left - 1] == 0)
                            count--;
                    }
                }
            }
        }

        return ans;
    }
};