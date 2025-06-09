class Trie {
private:
    Trie* son[26]{};
    int val = 0;
public:
    Trie(){}

    void insert(string key, int val) {
        Trie* cur = this;
        for (char c : key) {
            c -= 'a';
            if (cur->son[c] == nullptr)
                cur->son[c] = new Trie();
            cur = cur->son[c];
        }
        cur->val = val;
    }

    int sum(string prefix) {
        Trie* cur = this;
        for (char c : prefix) {
            c -= 'a';
            if (cur->son[c] == nullptr)
                return 0;
            cur = cur->son[c];
        }

        int res = 0;
        auto dfs = [&](this auto dfs, Trie* node) -> void {
            if (node == nullptr)
                return;
            
            res += node->val;

            for (int i = 0; i < 26; i++) {
                dfs(node->son[i]);
            }
        };
        dfs(cur);

        return res;
    }
};

class MapSum {
    Trie* root = new Trie();
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        root->insert(key, val);
    }
    
    int sum(string prefix) {
        return root->sum(prefix);
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */