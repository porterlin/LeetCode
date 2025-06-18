// 透過位運算紀錄有沒有重複，cand[c] 表示 c 在中間時有幾種可能的答案。所以最後所有 1 的個數即為本題的解
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int suf[26]{};
        for (auto& c : s)
            suf[c - 'a']++;

        int pre[26]{}, cand[26]{};
        for (auto& c : s) {
            suf[c - 'a']--;
            for (int i = 0; i < 26; i++) {
                if (pre[i] > 0 && suf[i] > 0) {
                    cand[c - 'a'] |= (1 << i);
                }
            }
            pre[c - 'a']++;
        }

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            ans += popcount((unsigned)cand[i]);
        }
        return ans;
    }
};