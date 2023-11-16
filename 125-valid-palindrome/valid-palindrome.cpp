class Solution
{
    public:
        bool isPalindrome(string s)
        {
            int i=0,j=s.length()-1;
            bool flag=true;
            while(i<=j){
                char first = tolower(s[i]),last = tolower(s[j]);
                if(first<'0' || first>'9' && first<'a' || first>'z') i++;
                else if(last<'0' || last>'9' && last<'a' || last>'z') j--;
                else{
                    if(first!=last){
                        flag=false;
                        break;
                    }
                    j--;
                    i++;
                }
            }   
            return flag;
        }
};