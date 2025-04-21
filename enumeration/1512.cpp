class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> hash;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.find(nums[i]) != hash.end())
                cnt += hash[nums[i]];
            hash[nums[i]]++;
        }
        return cnt;
    }
};