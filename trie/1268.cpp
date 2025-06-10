class Trie {
private:
    Trie* son[26]{};
    vector<string> prefix;
public:
    Trie(){}

    void insert(string word) {
        Trie* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr)
                cur->son[c] = new Trie();
            cur = cur->son[c];
            cur->prefix.push_back(word);
            ranges::sort(cur->prefix);
            if (cur->prefix.size() > 3)
                cur->prefix.pop_back();
        }
    }

    vector<string> find(string_view word) {
        Trie* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr)
                return {};
            cur = cur->son[c];
        }
        return cur->prefix;
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie();
        for (auto& p : products)
            root->insert(p);
        
        int n = searchWord.size();
        vector<vector<string>> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = root->find(string_view(searchWord).substr(0, i + 1));
        }
        return ans;
    }
};