class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ranges::sort(g);
        ranges::sort(s);
        int ans = 0;

        int i = 0;
        for (int j = 0; j < s.size(); j++) {
            if (i < g.size() && s[j] >= g[i]) {
                ans++;
                i++;
            }
        }

        return ans;
    }
};