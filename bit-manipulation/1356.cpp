class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        ranges::sort(arr, [](auto a, auto b) {
            if (popcount((unsigned) a) == popcount((unsigned) b))
                return a < b;
            return popcount((unsigned) a) < popcount((unsigned) b);
        });
        return arr;
    }
};