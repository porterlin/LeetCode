class Solution {
    vector<string> ans;
    vector<string> path;
public:
    void dfs(string s, int i) {
        if (path.size() > 4)
            return;
        
        if (i == s.size()) {
            if (path.size() != 4)
                return;
            
            string buf;
            for (int j = 0; j < path.size(); j++) {
                buf += path[j];
                if (j != path.size() - 1)
                    buf.push_back('.');
            }

            ans.push_back(buf);
            return;
        }

        unsigned long long x = 0;
        for (int j = i; j < s.size(); j++) {
            if (s[i] == '0' && j - i > 0)
                continue;
            
            x = x * 10 + s[j] - '0';
            if (x > 255)
                continue;

            path.push_back(to_string(x));
            dfs(s, j + 1);
            path.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0);
        return ans;
    }
};