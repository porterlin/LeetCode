class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixXor(arr.size() + 1);
        for (int i = 0; i < arr.size(); i++)
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];

        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int xorResult = prefixXor[queries[i][1] + 1] ^ prefixXor[queries[i][0]];
            ans[i] = xorResult;
        }
        return ans;
    }
};