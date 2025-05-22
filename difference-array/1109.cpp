class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> d(n + 2);
        for (auto& b : bookings) {
            int first = b[0], last = b[1], seats = b[2];
            d[first] += seats;
            d[last + 1] -= seats;
        }

        vector<int> ans(n);
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += d[i];
            ans[i - 1] = sum;
        }
        return ans;
    }
};