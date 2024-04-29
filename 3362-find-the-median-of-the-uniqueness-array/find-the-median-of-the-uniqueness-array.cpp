class Solution {
public:
    long long countSub(int k, vector<int>& nums) {
        long long res = 0, n = nums.size();
        unordered_map<int, int> count;
        for (int i = 0, j = 0; j < n; j++) {
            count[nums[j]]++;
            while (count.size() > k) {
                if (--count[nums[i]] == 0)
                    count.erase(nums[i]);
                i++;
            }
            res += j - i + 1;
        }
        return res;
    }
    int medianOfUniquenessArray(vector<int>& nums) {
        long long total = (long long)nums.size() * (nums.size() + 1) / 2;
        // this is cool
        int left = 1,
            right = unordered_set<int>(nums.begin(), nums.end()).size();
        while (left < right) {
            int k = (left + right) / 2;
            if (countSub(k,nums) * 2 >= total)
                right = k;
            else
                left = k + 1;
        }
        return left;
    }
};