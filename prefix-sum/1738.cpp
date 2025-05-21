class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        priority_queue<int, vector<int>, greater<>> minHeap;
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> sum(m + 1, vector<int>(n + 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum[i + 1][j + 1] = sum[i + 1][j] ^ sum[i][j + 1] ^ sum[i][j] ^ matrix[i][j];
                minHeap.push(sum[i + 1][j + 1]);
                if (minHeap.size() > k)
                    minHeap.pop();
            }
        }
        return minHeap.top();
    }
};