class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size(), check = 0;
        vector<bool> vis(n);

        auto dfs = [&](this auto&& dfs, int i) -> void {
            vis[i] = 1;
            check++;
            for (auto& next : rooms[i]) {
                if (!vis[next])
                    dfs(next);
            }
        };

        dfs(0);
        return check == n;
    }
};