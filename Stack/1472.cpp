class BrowserHistory {
    vector<string> history;
    int index = -1;
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        index++;
    }
    
    void visit(string url) {
        history.erase(history.begin() + index + 1, history.end());
        history.push_back(url);
        index++;
    }
    
    string back(int steps) {
        if (steps > index) {
            index = 0;
            return history[0];
        }
        index -= steps;
        return history[index];
    }
    
    string forward(int steps) {
        if (history.size() - index <= steps) {
            index = history.size() - 1;
            return history.back();
        }
        index += steps;
        return history[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */