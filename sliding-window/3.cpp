class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> mymap;
            int ans = 0, left = 0;
            for (int right = 0; right < s.size(); right++) {
                mymap[s[right]]++;
                while (mymap[s[right]] > 1) {
                    mymap[s[left]]--;
                    left++;
                }
                ans = max(ans, right - left + 1);
            }
            return ans;
        }
    };