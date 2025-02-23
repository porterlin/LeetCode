class Solution {
public:
    int lower_bound(vector<int>& nums, int target) {
        int mid;
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            mid = floor((left + right) / 2);
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound(nums, target);
        if (start == nums.size() || nums[start] != target)
            return {-1, -1};
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};