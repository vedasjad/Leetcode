class Solution
{
    public:
        bool isValid(string s)
        {
            stack<char> brackets;
            bool flag = true;
            for (char c: s)
            {
                if (c == '(' || c == '{' || c == '[')
                {
                    brackets.push(c);
                }
                else
                {
                    if (c == ')')
                    {
                        if (!brackets.empty() && brackets.top() == '(') brackets.pop();
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                    else if (c == '}')
                    {
                        if (!brackets.empty() && brackets.top() == '{') brackets.pop();
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                    else
                    {
                        if (!brackets.empty() && brackets.top() == '[') brackets.pop();
                        else
                        {
                            flag = false;
                            break;
                        }
                    }
                }
            }
            if (!brackets.empty()) flag = false;
            return flag;
        }
};