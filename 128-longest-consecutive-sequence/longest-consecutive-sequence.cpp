class Solution
{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            int maxLength = 0, currLength = 0, lastNum = INT_MIN;
            for (auto it: nums)
            {
                if (currLength == 0)
                {
                    currLength++;
                    maxLength = max(maxLength, currLength);
                }
                else
                {
                    if (lastNum + 1 == it)
                    {
                        currLength++;
                        maxLength = max(maxLength, currLength);
                    }
                    else if (lastNum == it) continue;
                    else

                        currLength = 1;
                }
                lastNum = it;
            }
            return maxLength;
        }
};