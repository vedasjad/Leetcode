class Solution
{
    public:
        int trap(vector<int> &height)
        {
            int i = 0, j = 1, currWater = 0, maxWater = 0, first = 0, last = 0;
            while (j < height.size())
            {
                first = height[i], last = height[j];
                if (first == 0)
                {
                    i++;
                    j++;
                }
                else if (last < first)
                {
                    currWater += first - last;
                    j++;
                }
                else
                {
                    maxWater += currWater;
                    currWater = 0;
                    i = j++;
                }
            }
            int maxFirst = i;
            if (last < first)
            {
                j = height.size() - 1, i = height.size() - 2;
                first = height[i], last = height[j], currWater = 0;
                while (i >= maxFirst)
                {
                    first = height[i], last = height[j];
                    if (last == 0)
                    {
                        i--;
                        j--;
                    }
                    else if (first < last)
                    {
                        currWater += last - first;
                        i--;
                    }
                    else
                    {
                        maxWater += currWater;
                        cout << currWater << endl;
                        currWater = 0;
                        j = i--;
                    }
                }
            }
            return maxWater;
        }
};