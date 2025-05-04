class Solution {
public:
    long long calculateScore(string s) {
        long long score = 0;
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < s.size(); i++) {
            auto it = mp.find('z' - (s[i] - 'a'));
            if (it != mp.end()) {
                if ((*it).second.size() > 0) {
                    score += (i - (*it).second[(*it).second.size() - 1]);
                    (*it).second.pop_back();
                } else {
                    mp[s[i]].push_back(i);
                }
            } else {
                mp[s[i]].push_back(i);
            }
        }
        return score;
    }
};