// time complexity: O(logn)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (citations[n - mid - 1] >= mid + 1)
                left  = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};