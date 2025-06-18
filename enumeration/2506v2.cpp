class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < words.size(); i++) {
            int mask = 0;
            for (auto& c : words[i]) {
                mask |= (1 << (c - 'a'));
            }
            if (mp.contains(mask))
                ans += mp[mask];
            mp[mask]++;
        }
        return ans;
    }
};