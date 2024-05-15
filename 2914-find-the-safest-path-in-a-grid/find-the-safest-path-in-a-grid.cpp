class Solution {
public:
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    void bfs(vector<vector<int>>& grid, vector<vector<int>>& distance, int n) {
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && distance[newX][newY] > distance[x][y] + 1) {
                    distance[newX][newY] = distance[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = grid.size();
        if (grid[0][0] || grid[n - 1][n - 1]) return 0;

        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        bfs(grid, distance, n);
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({distance[0][0], {0, 0}});

        while (!pq.empty()) {
            auto [safe, coords] = pq.top();
            auto [x, y] = coords;
            pq.pop();

            if (x == n - 1 && y == n - 1) return safe;
            visited[x][y] = true;

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n && newY >= 0 && newY < n && !visited[newX][newY]) {
                    int newSafe = min(safe, distance[newX][newY]);
                    pq.push({newSafe, {newX, newY}});
                    visited[newX][newY] = true;
                }
            }
        }

        return -1;
    }
};
