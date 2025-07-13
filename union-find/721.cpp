class DSU {
public:
	vector<int> parent;
	vector<int> size;
	int cc;

	DSU(int n): parent(n), size(n, 1), cc(n) {
		ranges::iota(parent, 0);
	}

	int find(int x) {
		if (parent[x] == x)
			return x;
		return parent[x] = find(parent[x]);
	}

	bool is_same(int x, int y) {
		return find(x) == find(y);
	}

	bool merge(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y)
			return false;
		parent[x] = y;
		size[y] += size[x];
		size[x] = size[y];
		cc--;
		return true;
	}
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string, int> emailToIndex;
        unordered_map<string, string> emailToName;
        for (auto& account : accounts) {
            for (int i = 1; i < account.size(); i++) {
                string& email = account[i];
                if (!emailToIndex.contains(email)) {
                    emailToIndex[email] = emailToIndex.size();
                    emailToName[email] = account[0];
                }
            }
        }

        DSU dsu(emailToIndex.size());
        for (auto& account : accounts) {
            for (int i = 2; i < account.size(); i++) {
                dsu.merge(emailToIndex[account[1]], emailToIndex[account[i]]);
            }
        }

        unordered_map<int, vector<string>> indexToEmails;
        for (auto& [email, idx] : emailToIndex) {
            indexToEmails[dsu.find(idx)].push_back(email);
        }

        vector<vector<string>> ans;
        for (auto& [index, emails] : indexToEmails) {
            vector<string> buf;
            buf.push_back(emailToName[emails[0]]);
            for (auto& email : emails)
                buf.push_back(email);
            ans.push_back(buf);
        }
        return ans;
    }
};