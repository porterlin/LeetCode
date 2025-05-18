class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 0;
        vector<bool> valid(10);
        auto dfs = [&](this auto&& dfs, int i) {
            ans++;
            if (i == n)
                return;

            for (int j = 0; j < 10; j++) {
                if (i == 0 && j == 0)
                    continue;
                if (!valid[j]) {
                    valid[j] = true;
                    dfs(i + 1);
                    valid[j] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};