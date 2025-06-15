class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> graph(n, vector<int>(n, 1e9));
        for (auto& t : times)
            graph[t[0] - 1][t[1] - 1] = t[2];
        
        vector<int> dis(n, 1e9), done(n);
        dis[k - 1] = 0;
        while (true) {
            int x = -1;
            for (int i = 0; i < n; i++) {
                if (!done[i] && (x < 0 || dis[i] < dis[x]))
                    x = i;
            }
            if (x < 0)
                return ranges::max(dis);
            if (dis[x] == 1e9)
                return -1;
            done[x] = true;
            for (int y = 0; y < n; y++) {
                dis[y] = min(dis[y], dis[x] + graph[x][y]);
            }
        }
    }
};