class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> father(26);
        ranges::iota(father, 0);

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
        };

        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '=') {
                merge(equations[i][0] - 'a', equations[i][3] - 'a');
            }
        }

        for (int i = 0; i < equations.size(); i++) {
            if (equations[i][1] == '!') {
                int x = find(equations[i][0] - 'a');
                int y = find(equations[i][3] - 'a');
                if (x == y)
                    return false;
            }
        }
        return true;
    }
};