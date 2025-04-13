class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixSum(n + 1, 0);

        for (int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + arr[i];

        int ans = 0;
        int left = 0;
        int len = 0;
        for (int right = 0; right < n; right++, left = 0) {
            len = right - left + 1;
            while (left <= right) {
                if (len % 2 == 1)
                    ans += prefixSum[right + 1] - prefixSum[left];
                left++;
                len = right - left + 1;
            }
        }
        return ans;
    }
};