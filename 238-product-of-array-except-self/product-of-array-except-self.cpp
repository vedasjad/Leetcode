class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int zeroes = count(nums.begin(), nums.end(), 0), pro = 1;
            if (zeroes > 1) return vector<int> (size(nums));
            for (auto num: nums)
                if (num) pro *= num;
            for (auto &num: nums)
                if (zeroes) num = num ? 0 : pro;
                else num = pro / num;
            return nums;
        }
};