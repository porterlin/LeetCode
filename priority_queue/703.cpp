class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        index = k;
        for (auto num : nums)
            add(num);
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > index)
            minHeap.pop();
        return minHeap.top();
    }
private:
    priority_queue<int, vector<int>, greater<>> minHeap;
    int index;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */