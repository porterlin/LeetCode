class Solution {
    int ans = 0;
    string path;
public:
    bool check() {
        unordered_set<char> s;
        for (auto p : path) {
            if (s.count(p))
                return false;
            s.insert(p);
        }
        return true;
    }

    void dfs(vector<string>& arr, int i) {
        if (i == arr.size()) {
            if (check())
                ans = max(ans, (int)path.size());
            return;
        }

        dfs(arr, i + 1);

        path += arr[i];
        if (check()) // 沒加這行會 TLE
            dfs(arr, i + 1);
        path.erase(path.size() - arr[i].size(), arr[i].size());
    }

    int maxLength(vector<string>& arr) {
        dfs(arr, 0);
        return ans;
    }
};