class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int mx = INT_MIN, ans = INT_MIN;
        for (int i = 0; i < values.size(); i++) {
            ans = max(ans, mx + values[i] - i);
            mx = max(mx, values[i] + i);
        }
        return ans;
    }
};