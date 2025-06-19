class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<long long>> dis(n, vector<long long>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dis[i][j] = pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2);
            }
        }

        int ans = 0;
        for (auto& ind : dis) {
            unordered_map<long long, int> mp;
            for (auto& v : ind) {
                if (mp.contains(v))
                    ans += mp[v] * 2;
                mp[v]++;
            }
        }
        return ans;
    }
};