class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 100000;
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) < abs(ans - target))
                    ans = sum;

                if (sum == target)
                    return ans;
                else if (sum > target)
                    k--;
                else if (sum < target)
                    j++;
            }
        }
        return ans;
    }
};