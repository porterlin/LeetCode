class Solution {
public:
    int countTestedDevices(vector<int>& batteryPercentages) {
        int dec = 0;
        for (auto& b : batteryPercentages)
            if (b - dec > 0)
                dec++;
        return dec;
    }
};