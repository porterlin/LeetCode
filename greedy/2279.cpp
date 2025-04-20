class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for (int i = 0; i < capacity.size(); i++)
            capacity[i] -= rocks[i];
        
        ranges::sort(capacity);
        for (int c : capacity)
            cout << c << endl;
        int ans = 0;
        for (auto a : capacity) {
            if (additionalRocks - a >= 0)
                additionalRocks -= a;
            else
                break;
            ans++;
        }
        return ans;
    }
};