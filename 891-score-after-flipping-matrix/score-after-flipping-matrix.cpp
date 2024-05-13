class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        unordered_set<int> irow, icol;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            if (!grid[i][0])
                irow.insert(i);
        }
        int count = 0;
        for (int i = 1; i < n; i++) {
            count = 0;
            for (int j = 0; j < m; j++) {
                if (irow.count(j) && !grid[j][i]) {
                    count++;
                }
                if (!irow.count(j) && grid[j][i]) {
                    count++;
                }
            }
            if (count <= m / 2) {
                icol.insert(i);
            }
        }
        // for(auto it:irow){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        // for(auto it:icol){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        int total = 0, row = 0;
        for (int i = 0; i < m; i++) {
            row = 0;
            for (int j = 0; j < n; j++) {
                if (irow.count(i) && icol.count(j)) {
                    if (grid[i][j])
                        row += pow(2, n - 1 - j);
                } else if (irow.count(i) ^ icol.count(j)) {
                    if (!grid[i][j])
                        row += pow(2, n - 1 - j);
                } else if (!irow.count(i) && !icol.count(j)) {
                    if (grid[i][j])
                        row += pow(2, n - 1 - j);
                }
            }
            // cout<<row<<endl;
            total += row;
        }
        return total;
    }
};