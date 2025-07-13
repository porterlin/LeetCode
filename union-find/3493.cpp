class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size(), m = properties[0].size();
        int cc = n;
        vector<int> father(n);
        iota(father.begin(), father.end(), 0);

        auto find = [&](this auto&& find, int x) -> int {
            if (father[x] == x)
                return x;
            return father[x] = find(father[x]);
        };

        auto merge = [&](int x, int y) {
            x = find(x);
            y = find(y);
            if (x == y)
                return;

            father[x] = y;
            cc--;
        };

        vector<unordered_set<int>> st(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < properties[i].size(); j++) {
                st[i].insert(properties[i][j]);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j)
                    break;
                int cnt = 0;
                for (auto& v : st[i]) {
                    if (st[j].contains(v))
                        cnt++;
                }
                if (cnt >= k) {
                    merge(i, j);
                }
            }
        }
        return cc;
    }
};