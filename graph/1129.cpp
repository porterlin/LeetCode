class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> graph(n, vector<vector<int>>(2));
        for (auto& r : redEdges)
            graph[r[0]][0].push_back(r[1]);
        for (auto& b : blueEdges)
            graph[b[0]][1].push_back(b[1]);
        
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;
        for (int color = 0; color < 2; color++) {
            bool curColor = color;
            unordered_set<string> hash;
            queue<int> q;
            q.push(0);
            for (int step = 1; !q.empty(); step++) {
                int qsize = q.size();
                while (qsize--) {
                    int val = q.front();
                    q.pop();
                    for (auto& a : graph[val][curColor]) {
                        string str;
                        str += to_string(curColor) + "#" + to_string(val) + "#" + to_string(a);
                        if (hash.count(str))
                            continue;
                        ans[a] = min(ans[a], step); 
                        hash.insert(str);
                        q.push(a);
                    }
                }
                curColor = !curColor;
            }
        }

        for (auto& a : ans)
            if (a == INT_MAX)
                a = -1;
        return ans;
    }
};