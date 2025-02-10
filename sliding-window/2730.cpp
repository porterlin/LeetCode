class Solution {
    public:
        int longestSemiRepetitiveSubstring(string s) {
            int check = 0;
            int ans = 0;
            int left = 0;
            for (int right = 0; right < s.size(); right++) {
                if (right != 0 && s[right] == s[right-1])
                    check++;
                while (check > 1) {
                    left++;
                    if (s[left] == s[left-1])
                        check--;
                }
                ans = max(ans, right - left + 1);
            }
            return ans;
        }
    };