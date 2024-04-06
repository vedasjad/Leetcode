class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int high = matrix.size() - 1, low = 0;
        while (high - low > 1) {
            int mid = (high + low) / 2;
            if (matrix[mid][0] <= target) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        int rowIndex = matrix[high][0] > target ? low : high;
        high = matrix[rowIndex].size() - 1, low = 0;
        while (low < high) {
            int mid = (high + low) / 2;
            if (matrix[rowIndex][mid] < target) {
                low = mid + 1;
            } else if (matrix[rowIndex][mid] > target) {
                high = mid - 1;
            } else {
                return true;
            }
        }
        return matrix[rowIndex][low] == target ? true : false;
    }
};