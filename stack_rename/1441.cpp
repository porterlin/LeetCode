class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int> cmp;
        vector<string> ans;
        int j = 0;
        for (int i = 1; i <= n; i++) {
            if (i == target[j]) {
                cmp.push_back(i);
                ans.push_back("Push");
                j++;
            } else {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if (cmp == target)
                break;
        }
        return ans;
    }
};