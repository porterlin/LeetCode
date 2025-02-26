class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int left = 0;
        int right = ranges::max(nums);
        int buf = right;
        int mid;

        auto check = [&](int target) -> bool {
            long long limit = 0;;
            for (int n : nums) {
                limit += n - target;
                if (limit > 0)
                    return false;
            }
            return true;
        };

        while (left <= right) {
            mid = left + (right - left) / 2;
            if (check(mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left > buf ? left - 1 : left;
    }
};