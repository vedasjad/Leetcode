class Solution
{
    public:
        int reverse(int num)
        {
            int rev = 0;
            while (num)
            {
                if (rev > INT_MAX / 10 || rev < INT_MIN / 10) return 0;
                rev = rev *10 + num % 10;
                num = num / 10;
            }
            return rev;
        }
};