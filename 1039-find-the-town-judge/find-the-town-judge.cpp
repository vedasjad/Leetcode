class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trusts) {
        if (n == 1 && trusts.size() == 0)
            return 1;
        vector<int> trustCount(n + 1, 0);
        for (auto& trust : trusts) {
            trustCount[trust[0]]--;
            trustCount[trust[1]]++;
        }
        for (int i = 0; i < n + 1; i++) {
            if (trustCount[i] == n - 1)
                return i;
        }
        return -1;
    }
};