class Solution {
public:
    int minChanges(int n, int k) {
        // 如果 n 和 k 的交集是 k，那麼 k 就是 n 的子集。
        return (n & k) != k ? -1 : popcount((unsigned) n ^ k);
    }
};