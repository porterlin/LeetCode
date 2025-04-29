class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 && popcount((unsigned) n) == 1 && bit_width((unsigned) n) % 2 == 1;
    }
};