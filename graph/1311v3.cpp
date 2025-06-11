// 先把 unordered_map 轉成 vector 再排序會比較快，就不用一直去 map 中找
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
        while (!q.empty()) {
            int f = q.front();
            q.pop();
            for (int j = 0; j < watchedVideos[f].size(); j++) {
                mp[watchedVideos[f][j]]++;
            }
        }

        vector<pair<string, int>> buf(mp.begin(), mp.end());
        ranges::sort(buf, [](auto& a, auto& b) {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second;
        });

        vector<string> ans;
        for (auto& [key, _] : buf)
            ans.push_back(key);
        return ans;
    }
};