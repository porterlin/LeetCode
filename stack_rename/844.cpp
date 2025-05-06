class Solution {
public:
    string cal(string s) {
        int slow = 0;
        for (int fast = 0; fast < s.size(); fast++) {
            if (s[fast] != '#') {
                s[slow] = s[fast];
                slow++;
            } else if (slow > 0) {
                slow--;
            }
        }
        s.resize(slow);
        return s;
    }

    bool backspaceCompare(string s, string t) {
        return cal(s) == cal(t);
    }
};