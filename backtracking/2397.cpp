class Solution {
    int path = 0;
    int ans = 0;
    int length;
public:
    void dfs(vector<int> bits, int numSelect, int i) {
        if (numSelect == 0) {
            int cnt = 0;
            int temp = path ^ ((1 << length) - 1);
            for (int j = 0; j < bits.size(); j++)
                if ((temp & bits[j]) == 0)
                    cnt++;

            ans = max(ans, cnt);
            return;
        }

        for (int j = i; j < length; j++) {
            path |= (1 << j);
            dfs(bits, numSelect - 1, j + 1);
            path ^= (1 << j);
        }
    }

    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int n = matrix.size();
        length = matrix[0].size();
        vector<int> bits(n);
        for (int i = 0; i < n; i++) {
            int buf = 0;
            for (int j = length - 1; j >= 0; j--)
                if (matrix[i][j] == 1)
                    buf |= (1 << (length - 1 - j));

            bits[i] = buf;
        }

        dfs(bits, numSelect, 0);

        return ans;
    }
};