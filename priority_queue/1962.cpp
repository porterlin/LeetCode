class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        make_heap(piles.begin(), piles.end());
        while (k--) {
            pop_heap(piles.begin(), piles.end());
            int* val = &piles.back();
            *val -= *val / 2;
            push_heap(piles.begin(), piles.end());
        }
        return reduce(piles.begin(), piles.end());
    }
};