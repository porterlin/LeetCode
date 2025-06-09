class Trie {
private:
    Trie* son[26]{};
    bool end = false;
public:
    Trie(){}

    void insert(string word) {
        Trie* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr)
                cur->son[c] = new Trie();
            cur = cur->son[c];
        }
        cur->end = true;
    }

    bool find(string word) {
        Trie* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr || cur->son[c]->end == false)
                return false;
            cur = cur->son[c];
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* root = new Trie();
        for (auto& s : words)
            root->insert(s);

        string ans = "";
        for (auto& s : words) {
            if (root->find(s)) {
                if (s.size() > ans.size())
                    ans = s;
                else if (s.size() == ans.size())
                    ans = s < ans ? s : ans;
            }
        }
        return ans;
    }
};