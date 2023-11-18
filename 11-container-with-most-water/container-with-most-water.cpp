class Solution
{
    public:
        int maxArea(vector<int> &height)
        {
            int i = 0, j = height.size() - 1, maxWater = 0, currWater = 0;
            while (i < j)
            {
                currWater = min(height[i], height[j]) *(j - i);
                maxWater = max(currWater, maxWater);
                if (height[i] < height[j]) i++;
                else j--;
            }
            return maxWater;
        }
};