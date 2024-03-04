class Solution
{
    public:
        vector<int> dailyTemperatures(vector<int> &temperatures)
        {
            stack<pair<int, int>> nums;
            vector<int> ans(temperatures.size(), 0);
            for (int i = 0; i < temperatures.size(); i++)
            {
                pair<int, int> num = make_pair(temperatures[i], i);
                if(nums.empty()){
                    nums.push(num);
                    continue;
                }
                while (!nums.empty() && num.first > nums.top().first)
                {
                    ans[nums.top().second] = num.second - nums.top().second;
                    nums.pop();
                }
                nums.push(num);
            }
            return ans;
        }
};