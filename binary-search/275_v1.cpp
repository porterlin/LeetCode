// time complexity: O(nlogn)
class Solution {
public:
    bool check(vector<int>& citations, int mid) {
        int h_index = mid + 1;
        int check = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= h_index)
                check++;
        }
        if (check >= h_index)
            return true;
        return false;
    }

    int binary_search(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        int mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (check(citations, mid))
                left  = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }

    int hIndex(vector<int>& citations) {
        return binary_search(citations);
    }
};