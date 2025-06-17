class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mn = arrays[0][0], mx = arrays[0].back(), ans = INT_MIN;
        for (int i = 1; i < arrays.size(); i++) {
            int curMin = arrays[i][0];
            int curMax = arrays[i].back();
            ans = max({ans, abs(mx - curMin), abs(mn - curMax)});
            mn = min(mn, curMin);
            mx = max(mx, curMax);
        }
        return ans;
    }
};