class Solution {
public:
    void visitLand(int i, int j, vector<int>& farmLand,
                   vector<vector<int>>& land) {
        if (i < 0 || j < 0 || i >= land.size() || j >= land[i].size() ||
            land[i][j] == 0) {
            return;
        }
        land[i][j] = 0;
        farmLand[2] = max(farmLand[2], i);
        farmLand[3] = max(farmLand[3], j);
        visitLand(i, j + 1, farmLand, land);
        visitLand(i, j - 1, farmLand, land);
        visitLand(i - 1, j, farmLand, land);
        visitLand(i + 1, j, farmLand, land);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> farms;
        for (int i = 0; i < land.size(); i++) {
            for (int j = 0; j < land[i].size(); j++) {
                if (land[i][j]) {
                    vector<int> farmLand = {i, j, i, j};
                    visitLand(i, j, farmLand, land);
                    farms.push_back(farmLand);
                }
            }
        }
        return farms;
    }
};