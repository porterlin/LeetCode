class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        unordered_map<int, array<int, 4>> mp;
        mp[indexDifference] = {nums[0], 0, nums[0], 0};
        for (int i = indexDifference; i < nums.size(); i++) {
            if (i != indexDifference) {
                if (mp[i - 1][0] < nums[i - indexDifference]) {
                    mp[i][0] = mp[i - 1][0];
                    mp[i][1] = mp[i - 1][1];
                } else if (mp[i - 1][0] >= nums[i - indexDifference]) {
                    mp[i][0] = nums[i - indexDifference];
                    mp[i][1] = i - indexDifference;
                }
                if (mp[i - 1][2] >= nums[i - indexDifference]) {
                    mp[i][2] = mp[i - 1][2];
                    mp[i][3] = mp[i - 1][3];
                } else if (mp[i - 1][2] < nums[i - indexDifference]) {
                    mp[i][2] = nums[i - indexDifference];
                    mp[i][3] = i - indexDifference;
                }
            }

            if (abs(nums[i] - mp[i][0]) >= valueDifference)
                return {mp[i][1], i};
            if (abs(nums[i] - mp[i][2]) >= valueDifference)
                return {mp[i][3], i};
        }
        return {-1, -1};
    }
};