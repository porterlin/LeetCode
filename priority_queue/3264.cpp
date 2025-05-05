class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<int, vector<int>, greater<>> minHeap(nums.begin(), nums.end());
        while (k--) {
            int top = minHeap.top();
            minHeap.pop();
            auto it = ranges::find(nums, top);
            *it = top * multiplier;
            minHeap.push(top * multiplier);
        }
        return nums;
    }
};