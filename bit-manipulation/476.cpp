class Solution {
public:
    int findComplement(int num) {
        return num ^ ((1ULL << bit_width((unsigned) num)) - 1); // 1ULL 防止 overflow
    }
};