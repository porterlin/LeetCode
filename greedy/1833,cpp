class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        ranges::sort(costs);
        int ans = 0;
        for (int i = 0; i < costs.size(); i++) {
            if (coins - costs[i] >= 0)
                coins -= costs[i];
            else
                break;
            ans++;
        }
        return ans;
    }
};