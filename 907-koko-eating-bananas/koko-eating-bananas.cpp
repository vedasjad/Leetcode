class Solution {
public:
    bool isFeasible(int speed, vector<int>& piles, int h) {
        long long hours = 0;
        for (int pile : piles) {
            hours += (pile / speed) + ((pile % speed) ? 1 : 0);
        }
        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isFeasible(mid, piles, h)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};