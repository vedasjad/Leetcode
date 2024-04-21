class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (n == 1 || source == destination)
            return true;
        vector<bool> visited(n - 1, false);
        visited[source] = true;
        bool flag = true;
        while (flag) {
            flag = false;
            for (auto x : edges) {
                if ((visited[x[0]] == true and visited[x[1]] == false) or
                    (visited[x[0]] == false and visited[x[1]] == true)) {
                    visited[x[0]] = true;
                    visited[x[1]] = true;
                    flag = true;
                }
                if (visited[destination])
                    return true;
            }
        }
        return false;
    }
};