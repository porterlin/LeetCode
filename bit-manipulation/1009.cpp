class Solution {
public:
    int bitwiseComplement(int n) {
        return n == 0 ? 1 : n ^ ((1ULL << bit_width((unsigned) n)) - 1);
    }
};