class Trie {
private:
    Trie* son[27]{};
    string path = "~";
public:
    Trie(){}

    void insert(string word) {
        Trie* cur = this;
        for (char c : word) {
            if (c == '/')
                c = 26;
            else
                c -= 'a';
            if (cur->son[c] == nullptr)
                cur->son[c] = new Trie();
            cur = cur->son[c];
        }
        cur->path = word;
    }

    bool find(string word) {
        Trie* cur = this;
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c == '/')
                c = 26;
            else
                c -= 'a';
            if (cur->son[c] == nullptr)
                return false;
            cur = cur->son[c];
            if (cur->path != "~" && i != word.size() - 1 && word[i + 1] == '/')
                return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        Trie* root = new Trie();
        for (auto& s : folder)
            root->insert(s);
        
        vector<string> ans;
        for (auto& s : folder) {
            if (!root->find(s))
                ans.push_back(s);
        }
        return ans;
    }
};