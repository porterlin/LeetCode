class Solution {
public:
    int minBitFlips(int start, int goal) {
        return popcount((unsigned) start ^ goal);
    }
};