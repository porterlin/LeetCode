class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        while (k--) {
            int val = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(sqrt(val));
        }
        
        long long ans = 0;
        while (!maxHeap.empty()) {
            ans += maxHeap.top();
            maxHeap.pop();
        }
        return ans;
    }
};