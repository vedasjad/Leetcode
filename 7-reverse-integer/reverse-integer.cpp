class Solution
{
    public:
        int reverse(int num)
        {
            long rev = 0;
            bool sign = num > 0 ? false : true;
            num = abs(num);
            while (num > 0)
            {
                if (INT_MAX < rev *10) return 0;
                rev = rev *10 + num % 10;
                num /= 10;
            }
            return sign ? 0 - rev : rev;
        }
};