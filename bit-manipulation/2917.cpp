class Solution {
public:
    int findKOr(vector<int>& nums, int k) {
        bitset<32> ans;
        for (int i = 0; i < 32; i++) {
            int cnt = 0;
            for (int j = 0; j < nums.size(); j++) {
                int bit = (nums[j] >> i) & 1;
                if (bit == 1)
                    cnt++;
            }
            if (cnt >= k)
                ans.set(i);
        }
        return ans.to_ullong();
    }
};