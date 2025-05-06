class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> maxHeap;
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int distance = abs(queries[i][0]) + abs(queries[i][1]);
            maxHeap.push(distance);
            if (maxHeap.size() < k) {
                ans[i] = -1;
                continue;
            }
            if (maxHeap.size() > k)
                maxHeap.pop();
            ans[i] = maxHeap.top();
        }
        return ans;
    }
};