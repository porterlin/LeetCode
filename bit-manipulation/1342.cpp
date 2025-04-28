class Solution {
public:
    int numberOfSteps(int num) {
        return num == 0 ? 0 : bit_width((unsigned) num) + popcount((unsigned) num) - 1;
    }
};