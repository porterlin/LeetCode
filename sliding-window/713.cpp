class Solution {
    public:
        int numSubarrayProductLessThanK(vector<int>& nums, int k) {
            if (k <= 1) return 0;
    
            int ans = 0;
            int prod = 1;
            int left = 0;
            for (int right = 0; right < nums.size(); right++) {
                prod *= nums[right];
                while (prod >= k) {
                    prod /= nums[left++];
                }
                ans += (right - left + 1); // 代表子窗口以 right 結尾的數量
            }
            return ans;
        }
    };