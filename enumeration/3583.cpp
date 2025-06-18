class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        unordered_map<int, long long> suf;
        for (auto& a : nums)
            suf[a]++;
        
        long long ans = 0;
        unordered_map<int, long long> pre;
        for (int i = 0; i < nums.size(); i++) {
            suf[nums[i]]--;
            long long x = nums[i] * 2;
            if (pre.contains(x) && suf.contains(x))
                ans = (ans + pre[x] * suf[x]) % MOD;
            pre[nums[i]]++;
        }
        return ans;
    }
};