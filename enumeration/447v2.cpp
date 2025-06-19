// 跟 v1 做法一樣，只是合併一些程式碼，把空間複雜度從 O(n ^ 2) 壓到 O(n)
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans = 0;
        unordered_map<long long, int> mp;
        for (auto& p1 : points) {
            mp.clear();
            for (auto& p2 : points) {
                long long dis = pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
                if (mp.contains(dis))
                    ans += mp[dis] * 2;
                mp[dis]++;
            }
        }
        return ans;
    }
};