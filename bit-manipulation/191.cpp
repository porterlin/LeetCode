class Solution {
public:
    int hammingWeight(int n) {
        return popcount((unsigned) n);
    }
};