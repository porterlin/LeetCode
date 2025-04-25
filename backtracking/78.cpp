class Solution {
    vector<vector<int>> ans;
    vector<int> path;
public:
    void dfs(vector<int>& nums, int i) {
        if (i == nums.size()) {
            ans.push_back(path);
            return;
        }

        dfs(nums, i + 1);

        path.push_back(nums[i]);
        dfs(nums, i + 1);
        path.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
};