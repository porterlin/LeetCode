class Solution {
    public:
        int maximumBeauty(vector<int>& nums, int k) {
            int ans = 0;
            int left = 0;
            sort(nums.begin(), nums.end());
            for (int right = 0; right < nums.size(); right++) {
                while (nums[right] - nums[left] > 2*k) {
                    left++;
                }
                ans = max(ans, right - left + 1);
            }
            return ans;
        }
    };