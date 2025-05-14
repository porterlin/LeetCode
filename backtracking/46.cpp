class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> path(nums.size());
        vector<bool> check(nums.size());
        auto dfs = [&](this auto&& dfs, int i) {
            if (i == nums.size()) {
                ans.push_back(path);
                return;
            }

            for (int j = 0; j < nums.size(); j++) {
                if (check[j] == false) {
                    path[i] = nums[j];
                    check[j] = true;
                    dfs(i + 1);
                    check[j] = false;
                }
            }
        };

        dfs(0);
        return ans;
    }
};