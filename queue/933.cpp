class RecentCounter {
    queue<int> counter;
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        counter.push(t);
        while (t - 3000 > counter.front())
            counter.pop();
        return counter.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */