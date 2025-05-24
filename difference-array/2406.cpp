class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> diff;
        for (auto& interval : intervals) {
            diff[interval[0]]++;
            diff[interval[1] + 1]--;
        }

        int ans = 0, sum = 0;
        for (auto& [_, val] : diff) {
            sum += val;
            ans = max(ans, sum);
        }
        return ans;
    }
};