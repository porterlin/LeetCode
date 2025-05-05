class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if (s.empty()) {
            int buf = thre;
            thre++;
            return buf;
        }
        int buf = *s.begin();
        s.erase(buf);
        return buf;
    }
    
    void addBack(int num) {
        if (num < thre)
            s.insert(num);
    }
private:
    set<int> s;
    int thre = 1;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */