class Solution
{
    public:
        int dfs(vector<vector < int>> &grid, int i, int j)
        {
            if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] <= 0)
                return 0;
            grid[i][j] = -grid[i][j];
            auto res = max({ dfs(grid, i + 1, j),
                dfs(grid, i, j + 1),
                dfs(grid, i - 1, j),
                dfs(grid, i, j - 1) });
            grid[i][j] = -grid[i][j];
            return grid[i][j] + res;
        }

    int getMaximumGold(vector<vector < int>> &grid, int res = 0)
    {
        for (auto i = 0; i < grid.size(); ++i)
            for (auto j = 0; j < grid[i].size(); ++j)
                res = max(res, dfs(grid, i, j));
        return res;
    }
};