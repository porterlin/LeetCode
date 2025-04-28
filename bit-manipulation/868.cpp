class Solution {
public:
    int binaryGap(int n) {
        int length = bit_width((unsigned) n);
        int low = countr_zero((unsigned) n);
        int bit;
        int ans = 0;
        for (int high = low + 1; high < length; high++) {
            bit = (n >> high) & 1;
            if (bit == 1) {
                ans = max(ans, high - low);
                low = high;
            }
        }
        return ans;
    }
};