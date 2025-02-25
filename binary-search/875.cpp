class Solution {
public:
    bool check(vector<int>& piles, int mid, int h) {
        int sum = piles.size();
        for (int p : piles) {
            sum += (p - 1) / mid;
            if (sum > h)
                return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = ranges::max(piles);
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (!check(piles, mid, h))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};