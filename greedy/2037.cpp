class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        ranges::sort(seats, greater<>());
        ranges::sort(students, greater<>());
        int n = seats.size();
        int ans = 0;

        for (int i = 0; i < n; i++)
            ans += abs(seats[i] - students[i]);
        
        return ans;
    }
};