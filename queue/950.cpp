class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        ranges::sort(deck, greater<>());
        deque<int> dq;
        for (int i = 0; i < deck.size(); i++) {
            if (dq.size() >= 2) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(deck[i]);
        }
        vector<int> ans(dq.size());
        for (int i = 0; i < dq.size(); i++)
            ans[i] = dq[i];
        return ans;
    }
};