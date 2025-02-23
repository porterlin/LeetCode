class Solution {
public:
    long long binary_search(vector<int>& potions, long long success, long long spell) {
        int left = 0, right = potions.size() - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if ((long long)potions[mid] * spell < success)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        int start;
        for (int i = 0; i < spells.size(); i++) {
            start = binary_search(potions, success, spells[i]);
            spells[i] = m - start;
        }
        return spells;
    }
};