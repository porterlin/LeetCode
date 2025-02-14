// 相向雙指針
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int k = nums.size() - 1; k > 1; k--) {
            if (nums[0] + nums[1] > nums[k]) { // optimize 1
                ans += ((k + 1) * k * (k - 1)) / 6;
                break;
            }
            if (nums[k - 2] + nums[k - 1] <= nums[k]) { // optimize 2
                continue;
            }

            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    ans += (j - i);
                    j--;
                }
                else {
                    i++;
                }
            }
        }
        return ans;
    }
};