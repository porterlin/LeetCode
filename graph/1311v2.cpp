class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        int n = friends.size();
        vector<bool> vis(n);
        queue<int> q;
        q.push(id);
        vis[id] = 1;
        for (int step = 1; step <= level; step++) {
            int qsize = q.size();
            while (qsize--) {
                int val = q.front();
                q.pop();
                for (int i = 0; i < friends[val].size(); i++) {
                    int f = friends[val][i];
                    if (vis[f])
                        continue;
                    vis[f] = 1;
                    q.push(f);
                }
            }
        }

        unordered_map<string, int> mp;
        vector<string> ans;
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (int j = 0; j < watchedVideos[f].size(); j++) {
                if (!mp.count(watchedVideos[f][j])) {
                    ans.push_back(watchedVideos[f][j]);
                }
                mp[watchedVideos[f][j]]++;
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