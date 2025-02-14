// 同向雙指針(較麻煩)
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        if (nums.size() < 3)
            return ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1, k = i + 2;
            if (nums[i] == 0)
                continue;

            while (k < nums.size()) {
                if (nums[i] + nums[j] > nums[k]) {
                    ans += (k - j);
                    k++;
                }
                else if (nums[i] + nums[j] < nums[k]) {
                    j++;
                }
                else {
                    j++;
                    if (j == k)
                        k++;
                }
            }
        }
        return ans;
    }
};