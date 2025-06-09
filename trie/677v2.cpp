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
            cur->val += val;
        }
    }

    int sum(string prefix) {
        Trie* cur = this;
        for (char c : prefix) {
            c -= 'a';
            if (cur->son[c] == nullptr)
                return 0;
            cur = cur->son[c];
        }
        return cur->val;
    }
};

class MapSum {
    Trie* root = new Trie();
    unordered_map<string, int> mp;
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int delta = val;
        if (mp.count(key))
            delta -= mp[key];
        mp[key] = val;
        root->insert(key, delta);
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