class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        int d[52]{};
        for (auto& r : ranges) {
            int start = r[0], end = r[1];
            d[start]++;
            d[end + 1]--;
        }

        int sum = 0;
        for (int i = 0; i < 52; i++) {
            sum += d[i];
            if (i >= left && i <= right && sum <= 0)
                return false;
            if (i > right)
                break;
        }
        return true;
    }
};