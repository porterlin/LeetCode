class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<vector<int>> graph(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < friends[i].size(); j++)
                graph[i].push_back(friends[i][j]);
        }

        unordered_map<string, int> mp;
        vector<string> ans;
        vector<bool> vis(n);
        queue<int> q;
        q.push(id);
        vis[id] = 1;
        for (int step = 1; step <= level; step++) {
            int qsize = q.size();
            while (qsize--) {
                int val = q.front();
                q.pop();
                for (int i = 0; i < graph[val].size(); i++) {
                    int f = graph[val][i];
                    if (vis[f])
                        continue;
                    vis[f] = 1;
                    q.push(f);
                    if (step == level && f != id) {
                        for (int j = 0; j < watchedVideos[f].size(); j++) {
                            if (!mp.count(watchedVideos[f][j])) {
                                ans.push_back(watchedVideos[f][j]);
                            }
                            mp[watchedVideos[f][j]]++;
                        }
                    }
                }
            }
        }

        ranges::sort(ans, [&mp](string a, string b) {
            if (mp[a] == mp[b])
                return a < b;
            return mp[a] < mp[b];
        });
        return ans;
    }
};