class Solution {
public:
    bool hasAlternatingBits(int n) {
        for (int i = 0; i < bit_width((unsigned) n) - 1; i++)
            if (!(((n >> i) & 1) ^ ((n >> (i + 1)) & 1))) // 比較相鄰的 bit 是否相同
                return false;
        return true;
    }
};