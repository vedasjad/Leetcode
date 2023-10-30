class Solution
{
    public:
        vector<int> twoSum(vector<int> &nums, int target)
        {
            unordered_map<int, vector < int>> imap;
            for (int i = 0; i < nums.size(); i++)
            {
                imap[nums[i]].push_back(i);
            }
            sort(nums.begin(), nums.end());
            int i = 0, j = nums.size() - 1;
            vector<int> vec;
            while (i < j)
            {
                if (nums[i] + nums[j] == target)
                {
                    vec.push_back(imap[nums[i]][0]);
                    imap[nums[i]].erase(imap[nums[i]].begin());
                    vec.push_back(imap[nums[j]][0]);
                    break;
                }
                else if (nums[i] + nums[j] < target)
                {
                    i++;
                }
                else
                {
                    j--;
                }
            }
            return vec;
        }
};