class Solution
{
    public:
        int findDuplicate(vector<int> &nums)
        {
            map<int, int> imap;
            for (int i = 0; i < nums.size(); i++)
            {
                imap[nums[i]]++;
            }
            for (auto it: imap)
            {
                if (it.second > 1) return it.first;
            }
            return 0;
        }
};