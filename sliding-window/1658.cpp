class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left = 0;
        int ans = 1e6;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < x)
            return -1;
        
        for (int right = 0; right < nums.size(); right++) {
            sum -= nums[right];
            while (sum < x) {
                sum += nums[left++];
            }
            if (sum == x)
                ans  = min(ans, (int)(nums.size() - (right - left + 1)));
        }
        return ans == 1e6 ? -1 : ans;
    }
};