class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int d[1001]{};
        for (auto& t : trips) {
            int numPassengers = t[0], from = t[1], to = t[2];
            d[from] += numPassengers;
            d[to] -= numPassengers;
        }

        int sum = 0;
        for (auto& val : d) {
            sum += val;
            if (sum > capacity)
                return false;
        }
        return true;
    }
};