class Solution {
public:
    bool check(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost, int target) {
        long long totalCost = 0;
        long long buf;
        for (int i = 0; i < k; i++) {
            totalCost = 0;
            for (int j = 0; j < n; j++) {
                buf = stock[j] >= (long long)composition[i][j] * (long long)target ? (long long)composition[i][j] * (long long)target : stock[j];
                totalCost += ((long long)composition[i][j] * (long long)target - buf) * (long long)cost[j];
            }
            if (totalCost <= budget)
                return true;
        }
        return false;
    }

    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int left = 0, right = INT_MAX;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (check(n, k, budget, composition, stock, cost, mid))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
};