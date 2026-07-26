class Solution {
public:

    bool canShip(vector<int>& weights, int cap, int days) {

        int days_needed = 1;
        int current_loaded = 0;

        for (int w : weights) {

            if (current_loaded + w > cap) {
                days_needed++;
                current_loaded = w;
            }
            else {
                current_loaded += w;
            }
        }

        return days_needed <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low < high) {

            int mid = low + (high - low) / 2;

            if (canShip(weights, mid, days)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};