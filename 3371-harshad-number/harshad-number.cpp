class Solution
{
    public:
        int sumOfTheDigitsOfHarshadNumber(int x)
        {
            int copy = x, sum = 0;
            while (x)
            {
                sum += x % 10;
                x /= 10;
            }
            if (copy % sum == 0) return sum;
            return -1;
        }
};