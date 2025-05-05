class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<>> minHeap(nums.begin(), nums.end());
        int ans = 0;
        while (true) {
            if (minHeap.top() >= k)
                break;
            if (minHeap.size() >= 2) {
                long long x = minHeap.top();
                minHeap.pop();
                long long y = minHeap.top();
                minHeap.pop();
                minHeap.push(x * 2 + y);
                ans++;
            }
        }
        return ans;
    }
};