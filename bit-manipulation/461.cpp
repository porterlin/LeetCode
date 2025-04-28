class Solution {
public:
    int hammingDistance(int x, int y) {
        return popcount((unsigned) x ^ y);
    }
};