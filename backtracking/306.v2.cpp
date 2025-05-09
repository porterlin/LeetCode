// Follow up: 處理大數加法 overflow 問題
class Solution {
    vector<vector<int>> path;
public:
    bool check(vector<int>& a, vector<int>& b, vector<int>& c) { // true if a + b = c
        int buf = 0;
        vector<int> sum;
        for (int i = 0; i < a.size() || i < b.size(); i++) {
            if (i < a.size())
                buf += a[i];
            if (i < b.size())
                buf += b[i];
            
            sum.push_back(buf % 10);
            buf /= 10;
        }
        if (buf > 0)
            sum.push_back(buf);
        if (sum.size() != c.size())
            return false;
        for (int i = 0; i < sum.size(); i++)
            if (sum[i] != c[i])
                return false;
        return true;
    }

    bool dfs(string num, int i) {
        if (i == num.size())
            return path.size() > 2;

        for (int j = i; j < num.size(); j++) {
            if (num[i] == '0' && j - i > 0)
                return false;

            vector<int> x;
            for (int k = j; k >= i; k--)
                x.push_back(num[k] - '0');
            
            if ((path.size() >= 2) && !check(path[path.size() - 1], path[path.size() - 2], x))
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