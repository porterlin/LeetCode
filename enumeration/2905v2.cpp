class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int maxIndex = 0, minIndex = 0;
        for (int i = indexDifference; i < nums.size(); i++) {
            maxIndex = nums[i - indexDifference] > nums[maxIndex] ? i - indexDifference : maxIndex;
            minIndex = nums[i - indexDifference] < nums[minIndex] ? i - indexDifference : minIndex;    
            if (abs(nums[i] - nums[minIndex]) >= valueDifference)
                return {minIndex, i};
            if (abs(nums[i] - nums[maxIndex]) >= valueDifference)
                return {maxIndex, i};
        }
        return {-1, -1};
    }
};