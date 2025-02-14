class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int sum;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            if (nums[i] + nums[i + 1] + nums[i + 2] > 0) // optimize 1
                break;
            if (nums[i] + nums[nums.size() - 1] + nums[nums.size() - 2] < 0) // optimize 2
                continue;

            int j = i + 1, k = nums.size() - 1;
            
            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (sum > 0)
                    k--;
                else if (sum < 0)
                    j++;
                else {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    k--;
                    while (k > j && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};