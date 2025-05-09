class Solution {
    int sum = 0;
public:
    bool dfs(string s, int i, int target) {
        if (i == s.size()) {
            return sum == target;
        }

        int buf = 0;
        for (int j = i; j < s.size(); j++) {
            buf = buf * 10 + s[j] - '0'; // O(1) 算子字串和
            sum += buf;
            if (dfs(s, j + 1, target))
                return true;
            sum -= buf;
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            sum = 0;
            if (dfs(s, 0, i))
                ans += i * i;
        }
        return ans;
    }
};