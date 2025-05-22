class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> d;
        for (auto& t : trips) {
            int numPassengers = t[0], from = t[1], to = t[2];
            d[from] += numPassengers;
            d[to] -= numPassengers;
        }

        int sum = 0;
        for (auto& [_, val] : d) {
            sum += val;
            if (sum > capacity)
                return false;
        }
        return true;
    }
};