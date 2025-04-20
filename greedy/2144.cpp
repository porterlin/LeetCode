class Solution {
public:
    int minimumCost(vector<int>& cost) {
        ranges::sort(cost, greater<>());
        int ans = 0;
        for (int i = 0; i < cost.size(); i++) {
            ans += cost[i];
            if (i + 1 >= cost.size())
                break;
            ans += cost[i + 1];
            i += 2;
        }
        return ans;
    }
};