class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) {
            s.insert(i);
            pq.push(i);
        }
    }
    
    int popSmallest() {
        int val = pq.top();
        pq.pop();
        s.erase(val);
        return val;
    }
    
    void addBack(int num) {
        if (s.count(num))
            return;

        pq.push(num);
        s.insert(num);
    }
private:
    priority_queue<int, vector<int>, greater<>> pq;
    unordered_set<int> s;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */