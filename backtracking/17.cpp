class Solution {
    string MAPPING[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    string path;
public:
    void dfs(string digits, int i) {
        if (i == digits.size()) {
            ans.push_back(path);
            return;
        }

        string letters = MAPPING[digits[i] - '0'];
        for (auto c : letters) {
            path[i] = c;
            dfs(digits, i + 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits == "")
            return {};
        
        path.resize(digits.size(), 0);
        dfs(digits, 0);
        return ans;
    }
};