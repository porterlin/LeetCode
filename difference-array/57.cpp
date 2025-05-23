class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        map<int, int> diff;
        for (auto& interval : intervals) {
            diff[interval[0]]++;
            diff[interval[1]]--;
        }

        diff[newInterval[0]]++;
        diff[newInterval[1]]--;

        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        for (auto& [key, val] : diff) {
            sum += val;
            if (path.size() == 0) {
                path.push_back(key);
            }
            if (sum == 0) {
                path.push_back(key);
                ans.push_back(path);
                path.clear();
            }
        }
        return ans;
    }
};