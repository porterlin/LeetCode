class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        // 定義最左邊一定是頂或是頂的左邊，那 mid 要跟 mid - 1 比
        // int left = 1;
        // int right = nums.size() - 1;
        // int mid;
        // while (left <= right) {
        //     mid = (left + right) / 2;
        //     if (nums[mid] > nums[mid - 1])
        //         left = mid + 1;
        //     else
        //         right = mid - 1;
        // }
        // return right;

        // 定義最右邊一定是頂或是頂的右邊，那 mid 要跟 mid + 1 比
        int left = 0;
        int right = nums.size() - 2;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};