class Solution {
public:
    int countTexts(string pressedKeys) {
        const int MOD = 1e9 + 7;
        int n = pressedKeys.size();
        vector<int> memo(n, -1);
        
        auto dfs = [&](this auto&& dfs, int i) -> int { 
            if (i == -1)
                return 1;
            if (memo[i] != -1)
                return memo[i];

            int mx = pressedKeys[i] == '7' || pressedKeys[i] == '9' ? 4 : 3;
    
            int cnt = 0;
            for (int j = 1; j <= mx && i - j >= -1 && pressedKeys[i - j + 1] == pressedKeys[i]; j++)
                cnt = (cnt + dfs(i - j)) % MOD;
            return memo[i] = cnt;
        };
        
        return dfs(n - 1);
    }
};