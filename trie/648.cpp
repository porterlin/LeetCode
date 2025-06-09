struct Node {
    Node* son[26]{};
    bool end = false;
};

class Solution {
    Node* root = new Node();

    void insert(string word) {
        Node* cur = root;
        for (char c : word) {
            c -= 'a';
            if (cur->son[c] == nullptr)
                cur->son[c] = new Node();
            cur = cur->son[c];
        }
        cur->end = true;
    }

    string find(string word) {
        Node* cur = root;
        string str;
        for (char c : word) {
            str.push_back(c);
            c -= 'a';
            if (cur->son[c] == nullptr)
                return word;
            if (cur->son[c]->end)
                return str;
            cur = cur->son[c];
        }
        return str;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        for (auto& d : dictionary)
            insert(d);

        stringstream ss(sentence);
        string word, ans;
        while (ss >> word) {
            ans += find(word) + " ";
        }
        ans.pop_back();
        return ans;
    }
};