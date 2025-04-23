class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<int> prefixSum(arr.size() + 1);
        for (int i = 0; i < arr.size(); i++)
            prefixSum[i + 1] = prefixSum[i] + arr[i];

        int even = 0;
        int odd = 0;
        int ans = 0;
        for (int i = 0; i < prefixSum.size(); i++) {
            if (prefixSum[i] % 2 == 0) {
                ans += odd;
                even++;
            } else {
                ans += even;
                odd++;
            }
            ans %= (int)(1e9 + 7);
        } 
        return ans;
    }
};