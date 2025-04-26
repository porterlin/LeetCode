class Solution {
    vector<string> ans;
    string path;
public:
    void dfs(string s, int i) {
        if (i == s.size()) {
            ans.push_back(path);
            return;
        }

        if (isalpha(s[i])) {
            for (int j = 0; j < 2; j++) {
                if (j % 2 == 0)
                    path.push_back(tolower(s[i]));
                else
                    path.push_back(toupper(s[i]));
                dfs(s, i + 1);
                path.pop_back();
            }
            return;
        }

        path.push_back(s[i]);
        dfs(s, i + 1);
        path.pop_back();
    }

    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return ans;
    }
};