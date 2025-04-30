class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        unsigned int MASK = (1 << n) - 1;
        for (int i = 0; i < (1 << n); i++) {
            int buf = i ^ MASK;
            if (((buf >> 1) & buf) == 0)
                ans.push_back(bitset<18>(buf ^ MASK).to_string().substr(18 - n));
        }
        return ans;
    }
};