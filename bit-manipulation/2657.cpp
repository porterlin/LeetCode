class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> C(A.size());
        unsigned long long bitA = 0, bitB = 0;
        for (int i = 0; i < A.size(); i++) {
            bitA |= 1ULL << A[i];
            bitB |= 1ULL << B[i];
            C[i] = popcount(bitA & bitB);
        }
        return C;
    }
};