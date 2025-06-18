class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        map<set<int>, int> mp;
        for (int i = 0; i < words.size(); i++) {
            set<int> cnt;
            for (auto& c : words[i]) {
                cnt.insert(c);
            }
            if (mp.contains(cnt))
                ans += mp[cnt];
            mp[cnt]++;
        }
        return ans;
    }
};