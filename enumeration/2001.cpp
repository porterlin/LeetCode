class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> hash;
        long long cnt = 0;
        for (int i = 0; i < rectangles.size(); i++) {
            double ratio = rectangles[i][0] / (double)rectangles[i][1];
            if (hash.find(ratio) != hash.end())
                cnt += hash[ratio];
            hash[ratio]++;
        }
        return cnt;
    }
};