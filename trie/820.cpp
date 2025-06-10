class Trie {
private:
    Trie* son[26]{};
    bool end = false;
public:
    Trie(){}

    void insert(string word) {
        Trie* cur = this;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            c -= 'a';
            if (cur->son[c] == nullptr)
                cur->son[c] = new Trie();   
            cur = cur->son[c];
            cur->end = false;
        }
        for (int i = 0; i < 26; i++) {
            if (cur->son[i] != nullptr)
                return;
        }
        cur->end = true;
    }

    int search() { 
        int ans = 0, path = -1;
        auto dfs = [&](this auto&& dfs, Trie* node) -> void {
            if (node == nullptr)
                return;
            if (node->end) {
                ans += path + 2;
                return;
            }

            path++;      
            for (int i = 0; i < 26; i++) {
                dfs(node->son[i]);
            }
            path--;
        };
        Trie* cur = this;
        dfs(cur);
        return ans;
    }
};

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        Trie* root = new Trie();
        for (auto& s : words) {
            ranges::reverse(s);
            root->insert(s);
        }
        return root->search();
    }
};