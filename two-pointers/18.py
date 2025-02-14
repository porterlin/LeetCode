class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        long long sum = 0;
        for (int a = 0; a < nums.size() - 3; a++) {
            if (nums.size() <= 3)
                break;
            if (a > 0 && nums[a] == nums[a - 1])
                continue;
            
            if ((long long)nums[a] + (long long)nums[a + 1] + (long long)nums[a + 2] + (long long)nums[a + 3] > target) // optimize 1
                break;
            if ((long long)nums[a] + (long long)nums[nums.size() - 3] + (long long)nums[nums.size() - 2] + (long long)nums[nums.size() - 1] < target) // optimize 2
                continue;

            for (int b = a + 1; b < nums.size() - 2; b++) {
                if (b > 1 && nums[b] == nums[b - 1] && b - 1 != a)
                    continue;
                int c = b + 1, d = nums.size() - 1;

                if ((long long)nums[b] + (long long)nums[b + 1] + (long long)nums[b + 2] > target - nums[a]) // optimize 3
                    break;
                if ((long long)nums[b] + (long long)nums[nums.size() - 2] + (long long)nums[nums.size() - 1] < target - nums[a]) // optimize 4
                    continue;

                while (c < d) {
                    sum = (long long)nums[a] + (long long)nums[b] + (long long)nums[c] + (long long)nums[d];
                    if (sum > target)
                        d--;
                    else if (sum < target)
                        c++;
                    else {
                        ans.push_back({nums[a], nums[b], nums[c], nums[d]});
                        d--;
                        while (c < d && nums[d] == nums[d + 1])
                            d--;
                        c++;
                        while (c < d && nums[c] == nums[c - 1])
                            c++;
                    }
                }
            }
        }
        return ans;
    }
};