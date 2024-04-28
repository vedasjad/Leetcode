class Solution {
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> diffs = {nums2[0] - nums1[0], nums2[0] - nums1[1],
                             nums2[0] - nums1[2]};
        sort(diffs.begin(), diffs.end());
        int i = 0, j = 0, k = 0, skipCount = 0;
        while (j < nums2.size()) {
            if (nums2[j] - nums1[i] == diffs[k]) {
                i++, j++;
            } else {
                if (skipCount == 2) {
                    skipCount = 0, k++, i = 0, j = 0;
                } else {
                    i++, skipCount++;
                }
            }
        }
        return diffs[k];
    }
};