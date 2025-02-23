class Solution {
public:
    int binary_search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = floor((left + right) / 2);
            if (nums[mid] < target)
                left  = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    int maximumCount(vector<int>& nums) {
        int start = binary_search(nums, 0);
        int end = binary_search(nums, 1);

        return max(start, int(nums.size() - end));
    }
};