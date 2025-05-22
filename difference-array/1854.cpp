class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> d;
        for (auto& log : logs) {
            int birth = log[0], death = log[1];
            d[birth]++;
            d[death]--;
        }

        int sum = 0;
        int maxPopulation = 0, year = 0;
        for (auto& [key, val] : d) {
            sum += val;
            if (sum > maxPopulation) {
                maxPopulation = sum;
                year = key;
            }
        }
        return year;
    }
};