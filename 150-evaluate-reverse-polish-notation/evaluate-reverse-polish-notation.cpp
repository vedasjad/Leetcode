class Solution
{
    public:
        int evalRPN(vector<string> &tokens)
        {
            stack<int> rpn;
            for (auto token: tokens)
            {
                if (token != "+" && token != "-" && token != "*" && token != "/")
                {
                    rpn.push(stoi(token));
                }
                else
                {
                    int num1 = rpn.top();
                    rpn.pop();
                    int num2 = rpn.top();
                    rpn.pop();
                    if (token == "+") rpn.push((num1 + num2));
                    else if (token == "-") rpn.push(num2 - num1);
                    else if (token == "*") rpn.push(num1 *num2);
                    else rpn.push(num2 / num1);
                }
            }
            return rpn.top();
        }
};