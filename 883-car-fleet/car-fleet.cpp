class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> fleet;
        for (int i = 0; i < position.size(); i++) {
            fleet.push_back(make_pair(
                position[i], (double)(target - position[i]) / speed[i]));
        }
        sort(fleet.begin(), fleet.end());
        double slowest = fleet[fleet.size()-1].second, fleetCount = 0;
        for (int i = fleet.size() - 2; i >= 0; i--) {
            if (fleet[i].second > slowest) {
                slowest = fleet[i].second;
                fleetCount++;
            }
        }
        return ++fleetCount;
    }
};