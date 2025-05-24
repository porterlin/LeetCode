class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double left = 1e9;
        double right = 0;
        for (auto& sq : squares) {
            right = max(right, (double)(sq[1] + sq[2]));
            left = min(left, (double)(sq[1]));
        }

        auto check = [&](double mid) -> bool {
            double areaDown = 0, areaUp = 0;
            for (auto& sq : squares) {
                if (mid >= sq[1] + sq[2])
                    areaDown += (double)sq[2] * sq[2];
                else if (mid - sq[1] > 0)
                    areaDown += (double)((mid - sq[1]) * sq[2]);

                if (mid <= sq[1])
                    areaUp += (double)sq[2] * sq[2];
                else if ((sq[1] + sq[2] - mid) > 0)
                    areaUp += (double)((sq[1] + sq[2] - mid) * sq[2]);
                
            }
            return areaDown < areaUp;
        };
        
        double mid;
        while (left <= right) {
            mid = (double)(left + (right - left) / 2);
            if (check(mid))
                left = mid + 0.0000001;
            else
                right = mid - 0.0000001;
        }
        return mid;
    }
};