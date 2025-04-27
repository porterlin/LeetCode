class Solution {
public:
    int minChanges(int n, int k) {
        // 如果 n 和 k 的聯集是 n，那麼 k 就是 n 的子集。
        return ((n | k) ^ n) != 0 ? -1 : popcount((unsigned) n ^ k);
    }
};