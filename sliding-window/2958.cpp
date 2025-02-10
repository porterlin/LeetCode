class Solution {
    public:
        int maxSubarrayLength(vector<int>& nums, int k) {
            unordered_map<int, int> mymap;
            int ans = 0;
            int left = 0;
            for (int right = 0; right < nums.size(); right++) {
                mymap[nums[right]]++;
                while (mymap[nums[right]] > k) {
                    mymap[nums[left]]--;
                    left++;
                }
                ans = max(ans, right - left + 1);
            }
            return ans;
        }
    };