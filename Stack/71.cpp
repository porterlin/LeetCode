class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        istringstream ss(path);
        string s;
        while (getline(ss, s, '/')) {
            if (s.empty() || s == ".")
                continue;

            if (s != "..") {
                st.push_back(s);
            } else if (!st.empty()) {
                st.pop_back();
            }
        }

        string ans;
        for (auto a : st) {
            ans += '/';
            ans += a;
        }
        return ans.empty() ? "/" : ans;
    }
};