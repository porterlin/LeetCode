class MyCalendarThree {
    map<int, int> diff;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        diff[startTime]++;
        diff[endTime]--;

        int sum = 0, ans = 0;
        for (auto& [_, val] : diff) {
            sum += val;
            if (sum > ans)
                ans = sum;
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */