class Solution {
    vector<unsigned long long> path;
public:
    bool dfs(string num, int i) {
        if (i == num.size())
            return path.size() > 2;
        
        unsigned long long x = 0;
        for (int j = i; j < num.size(); j++) {
            if (num[i] == '0' && j - i > 0)
                return false;

            x = x * 10 + num[j] - '0';
            if ((path.size() >= 2) && (path[path.size() - 1] + path[path.size() - 2] != x))
                continue;

            path.push_back(x);
            if (dfs(num, j + 1))
                return true;
            path.pop_back();
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        return num.size() >= 3 ? dfs(num, 0) : false;
    }
};