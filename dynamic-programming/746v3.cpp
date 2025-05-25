class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int f0 = 0, f1 = 0, new_f;
        for (int i = 2; i <= n; i++) {
            new_f = min(f1 + cost[i - 1], f0 + cost[i - 2]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};