class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 2;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] > nums[nums.size() - 1])
                left = mid + 1;
            else
                right = mid - 1;
        }
        return nums[left];
    }
};