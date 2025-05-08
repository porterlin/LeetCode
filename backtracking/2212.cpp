class Solution {
    vector<int> path;
    vector<int> bob;
    int cmp = 0;
public:
    void dfs(vector<int>& alice, int numArrows, int score, int i) {
        if (numArrows == 0) {
            if (score > cmp) {
                cmp = score;
                bob = path;
            }
            return;
        }
        
        if (numArrows < 0)
            return;

        for (int j = i; j >= 0; j--) {
            if (j != 0) {
                path[j] = alice[j] + 1;
                dfs(alice, numArrows - path[j], score + j, j - 1);
            } else {
                path[j] = numArrows;
                dfs(alice, 0, score, j - 1);
            }
            path[j] = 0;
        }
    }

    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        path.resize(aliceArrows.size());
        dfs(aliceArrows, numArrows, 0, 11);
        return bob;
    }
};