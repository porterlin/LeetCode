class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int suf[26]{};
        for (auto& c : s)
            suf[c - 'a']++;

        int pre[26]{};
        unordered_set<string> cand;
        for (auto& c : s) {
            suf[c - 'a']--;
            for (int i = 0; i < 26; i++) {
                if (pre[i] > 0 && suf[i] > 0) {
                    string str;
                    str.push_back(i + 'a');
                    str.push_back(c);
                    cand.insert(str);
                }
            }
            pre[c - 'a']++;
        }
        return cand.size();
    }
};