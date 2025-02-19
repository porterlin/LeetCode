class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int target = ranges::max(nums);
        long long ans = 0;
        int count = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == target)
                count++;
            while (count == k) {
                if (nums[left] == target)
                    count--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};