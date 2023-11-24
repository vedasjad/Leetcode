class Solution
{
    private:
        bool checkPalindrome(int left, int right)
        {
            char leftChar = tolower(s[left]), rightChar = tolower(s[right]);
            if (leftChar >= '0' && leftChar <= '9' || leftChar >= 'a' && leftChar <= 'z')
            {
                if (rightChar >= '0' && rightChar <= '9' || rightChar >= 'a' && rightChar <= 'z')
                {
                    if (leftChar == rightChar)
                    {
                        if (left + 1 < right - 1)
                        {
                            return checkPalindrome(left + 1, right - 1);
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    if (left < right - 1)
                    {
                        return checkPalindrome(left, right - 1);
                    }
                    else
                    {
                        return true;
                    }
                }
            }
            else
            {
                if (left + 1 < right)
                {
                    return checkPalindrome(left + 1, right);
                }
                else
                {
                    return true;
                }
            }
            return true;
        }

    public:
        string s;
    bool isPalindrome(string str)
    {
        s = str;
        return checkPalindrome(0, s.length() - 1);
    }
};