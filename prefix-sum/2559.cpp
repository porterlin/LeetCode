class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        set<char> s{'a', 'e', 'i', 'o', 'u'};
        vector<int> buf(words.size());
        for (int i = 0; i < words.size(); i++)
            if (s.count(words[i][0]) && s.count(words[i][words[i].size() - 1]))
                buf[i] = 1;

        vector<int> prefixSum(words.size() + 1);
        for (int i = 0; i < words.size(); i++)
            prefixSum[i + 1] = prefixSum[i] + buf[i];

        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            ans.push_back(prefixSum[end + 1] - prefixSum[start]);
        }
        return ans;
    }
};