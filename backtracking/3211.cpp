class Solution {
    vector<string> ans;
    string path;
public:
    void dfs(int n, int i) {
        if (i > 1 && path[path.size() - 1] == '0' && path[path.size() - 2] == '0')
            return;
        
        if (i == n) {
            ans.push_back(path);
            return;
        }
        
        for (int j = 0; j < 2; j++) {
            path.push_back(j + '0');
            dfs(n, i + 1);
            path.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        dfs(n, 0);
        return ans;
    }
};