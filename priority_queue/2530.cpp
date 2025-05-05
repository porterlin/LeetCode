class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<>> maxHeap(nums.begin(), nums.end());
        long long score = 0;
        while (k--) {
            int val = maxHeap.top();
            score += val;
            maxHeap.pop();
            maxHeap.push(ceil(val / 3.0));
        }
        return score;
    }
};