class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            vector<vector < int>> ans;
            sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; i++)
            {
                if (i > 0 && nums[i] != nums[i - 1] || i == 0)
                {
                    int first = i + 1, last = nums.size() - 1;
                    while (first < last)
                    {
                        if (nums[i] + nums[first] + nums[last] == 0)
                        {
                            while (first < nums.size() - 1 && nums[first] == nums[first + 1]) first++;
                            while (last > 0 && nums[last] == nums[last - 1]) last--;
                            ans.push_back(vector < int>
                            {
                                nums[i],
                                nums[first],
                                nums[last] });
                            first++;
                            last--;
                        }
                        else if (nums[i] + nums[first] + nums[last] < 0) first++;
                        else last--;
                    }
                }
            }
            return ans;
        }
};