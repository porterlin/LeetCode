class Solution {
public:
    int countTexts(string pressedKeys) {
        const int MOD = 1e9 + 7;
        int n = pressedKeys.size();
        vector<int> dp(n);
        
        for (int i = 0; i < n; i++) {
            int mx = pressedKeys[i] == '7' || pressedKeys[i] == '9' ? 4 : 3;
            for (int j = 1; j <= mx && i - j >= -1 && pressedKeys[i - j + 1] == pressedKeys[i]; j++) {
                if (i - j == -1) {
                    dp[i]++;
                    break;
                }
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
        
        return dp[n - 1];
    }
};