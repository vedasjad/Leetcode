class Solution
{
    public:

        void genPar(vector<string> &vec, string str, int left, int right)
        {
            if (left == 0 && right == 0)
            {
                vec.push_back(str);
                return;
            }
            if (right > 0) genPar(vec, str + ")", left, right - 1);
            if (left > 0) genPar(vec, str + "(", left - 1, right + 1);
        }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        genPar(ans, "", n, 0);
        return ans;
    }
};