class Solution {
public:
    void visitLand(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() ||
            grid[i][j] == '0') {
            return;
        }
        grid[i][j] = '0';
        visitLand(i,j-1,grid);
        visitLand(i,j+1,grid);
        visitLand(i-1,j,grid);
        visitLand(i+1,j,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for (int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    islands++;
                    visitLand(i,j,grid);
                }
            }
        }
        return islands;
    }
};