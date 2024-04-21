class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size();
        while (i < j) {
            int mid = (i + j) / 2;
            double num = (nums[mid] < nums[0]) == (target < nums[0]) ? nums[mid]
                         : target < nums[0]                          ? -INFINITY
                                                                     : INFINITY;
            if (num < target) {
                i = mid + 1;
            } else if (num > target) {
                j = mid;
            } else
                return mid;
        }
        return -1;
    }
};