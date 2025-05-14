class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        string path;
        int cntl = 0, cntr = 0;
        int n = 0;
        int a = 0;
        stack<char> st;
        for (auto& ss : s) {
            if (ss == '(')
                cntl++;
            else if (ss == ')')
                cntr++;
            
            if (st.empty() && ss == ')')
                continue;
            if (ss == '(') {
                st.push(ss);
                continue;
            }
            if (!isalpha(ss)) {
                if (st.top() == '(' && ss == ')') {
                    n++;
                    st.pop();
                }
            } else {
                a++;
            }
        }

        auto dfs = [&](this auto&& dfs, int i, int cntll, int cntrr) {
            if (cntll == n && cntll == cntrr && path.size() == n * 2 + a) {
                if (ranges::find(ans, path) == ans.end())
                    ans.push_back(path);
                return;
            }
            if (cntll > n || cntrr > n || i >= s.size())
                return;

            dfs(i + 1, cntll, cntrr);

            if (isalpha(s[i])) {
                path.push_back(s[i]);
                dfs(i + 1, cntll, cntrr);
                path.pop_back();
            }

            if (cntll < cntl && s[i] == '(') {
                path.push_back('(');
                dfs(i + 1, cntll + 1, cntrr);
                path.pop_back();
            }

            if (cntrr < cntll && s[i] == ')') {
                path.push_back(')');
                dfs(i + 1, cntll, cntrr + 1);
                path.pop_back();
            }
        };

        dfs(0, 0, 0);
        return ans;
    }
};