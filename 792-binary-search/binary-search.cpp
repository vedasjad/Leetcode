class Solution
{
    public:
        int search(vector<int> &nums, int target)
        {
            int low = 0, high = nums.size() - 1;
            while (low < high)
            {
                int mid = (high + low) / 2;
                if (nums[mid] > target)
                {
                    high = mid - 1;
                }
                else if (nums[mid] < target)
                {
                    low = mid + 1;
                }
                else
                {
                    return mid;
                }
            }
            return nums[low] != target ? -1 : low;
        }
};