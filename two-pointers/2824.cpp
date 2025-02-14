class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        int left = 0, right = n - 1;
        int sum = 0;
        sort(nums.begin(), nums.end());
        while (left < right) {
            sum = nums[left] + nums[right];
            if (sum < target) {
                ans += (right - left);
                left++;
            }
            else if (sum >= target) {
                right--;
            }
        }
        return ans;
    }
};