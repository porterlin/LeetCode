class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int d[102]{};
        int maxVal = 0;
        for (auto& num : nums) {
            int start = num[0], end = num[1];
            maxVal = max(maxVal, end + 1);
            d[start]++;
            d[end + 1]--;
        }

        int ans = 0, sum = 0;
        for (int i = 0; i < maxVal; i++) {
            sum += d[i];
            if (sum > 0)
                ans++;
        }
        return ans;
    }
};