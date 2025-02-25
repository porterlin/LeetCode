class Solution {
public:
    bool check(vector<int>& time, int totalTrips, long long mid) {
        long long sum = 0;
        for (int t : time) {
            sum += (long long)mid / t;
            if (sum >= totalTrips)
                return true;
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long left = 1;
        long long right = (long long)ranges::min(time) * totalTrips;
        long long mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (check(time, totalTrips, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};