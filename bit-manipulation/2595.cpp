class Solution {
public:
    vector<int> evenOddBit(int n) {
        int odd = popcount((unsigned) n & 0xaaaaaaaa);
        int even = popcount((unsigned) n & 0x55555555);
        return {even, odd};
    }
};