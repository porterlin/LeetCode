class Solution {
public:
    long long binary_search(span<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right) {
            mid = (right + left) / 2;
            if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long  ans = 0;
        long long start, end;
        for (int i = 0; i < nums.size() - 1; i++) {
            start = binary_search(span<int>(nums.begin() + i + 1, nums.end()), lower - nums[i]);
            end = binary_search(span<int>(nums.begin() + i + 1, nums.end()), upper - nums[i] + 1) - 1;
            if (end >= start)
                ans += end - start + 1;
        }
        return ans;
    }
};