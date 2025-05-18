class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        ranges::sort(nums);
        vector<vector<int>> ans;
        do {
            ans.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};