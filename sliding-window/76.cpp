class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> s_map;
        unordered_map<char, int> target;
        for (char e : t)
            target[e]++;
        
        int left = 0, ans_right = 1e7, ans_left = 0;
        for (int right = 0; right < s.size(); right++) {
            s_map[s[right]]++;
            while (check(s_map, target)) {
                if (right - left < ans_right - ans_left) {
                    ans_right = right;
                    ans_left = left;
                }
                s_map[s[left]]--;
                left++;
            }
        }
        return ans_right == 1e7 ? "" : s.substr(ans_left, ans_right - ans_left + 1);
    }

    bool check(unordered_map<char, int>& s, unordered_map<char, int>& t) {
        for (const auto& [ch, count] : t)
            if (s[ch] < count)
                return false;
        return true;
    }
};