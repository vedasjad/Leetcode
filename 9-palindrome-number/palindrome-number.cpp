class Solution
{
    public:
        bool isPalindrome(int n)
        {
            if (n < 0) return false;
            long copy = n, rev = 0;
            while (copy)
            {
                rev = rev *10 + copy % 10;
                copy /= 10;
            }
            return rev == n;
        }
};