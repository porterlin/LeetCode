class Trie {
private:
    Trie* son[26]{};
    int cnt = 0;
public:
    Trie(){}

    void insert(string& word) {
        Trie* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr)
                cur->son[c] = new Trie();
            cur->son[c]->cnt++;
            cur = cur->son[c];
        }
    }

    int find(string& word) {
        Trie* cur = this;
        int res = 0;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr)
                return res;
            res += cur->son[c]->cnt;
            cur = cur->son[c];
        }
        return res;
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie* root = new Trie();
        for (auto& s : words)
            root->insert(s);

        int n = words.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {   
            ans[i] = root->find(words[i]);
        }
        return ans;
    }
};