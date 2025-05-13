class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string path;
        auto dfs = [&](this auto&& dfs, int i, int cntl, int cntr) {
            if (path.size() == 2 * n) {
                if (cntl == cntr)
                    ans.push_back(path);
                return;
            }

            if (cntl < n) {
                path.push_back('(');
                dfs(i + 1, cntl + 1, cntr);
                path.pop_back();
            }

            if (cntr < cntl) {
                path.push_back(')');
                dfs(i + 1, cntl, cntr + 1);
                path.pop_back();
            }
        };

        dfs(0, 0, 0);
        return ans;
    }
};