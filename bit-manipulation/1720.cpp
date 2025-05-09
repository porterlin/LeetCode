class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans;
        ans.push_back(first);
        for (auto e : encoded) {
            first ^= e;
            ans.push_back(first);
        }
        return ans;
    }
};