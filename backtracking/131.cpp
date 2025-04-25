class Solution {
    vector<vector<string>> ans;
    vector<string> path;
public:
    void dfs(string s, int i) {
        if (i == s.size()) {
            ans.push_back(path);
            return;
        }

        for (int j = 1; j < s.size() - i + 1; j++) {
            string buf = s.substr(i, j);
            string rbuf = buf;
            ranges::reverse(rbuf);
            if (buf == rbuf) {
                path.push_back(buf);
                dfs(s, i + j);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return ans;
    }
};