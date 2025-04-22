class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minValue = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            ans = max(ans, prices[i] - minValue);
            minValue = min(minValue, prices[i]);
        }
        return ans;
    }
};