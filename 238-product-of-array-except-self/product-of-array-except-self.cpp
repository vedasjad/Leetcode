class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> pre(n), answer(n), post(n);
            pre[0] = 1;
            post[n - 1] = 1;
            for (int i = 1; i < n; i++)
            {
                pre[i] = pre[i - 1] *nums[i-1];
            }
            for (int i = n - 2; i >= 0; i--)
            {
                post[i] = post[i + 1] *nums[i+1];
            }
            for (int i = 0; i < n; i++)
            {
                answer[i] = pre[i] *post[i];
            }
            return answer;
        }
};