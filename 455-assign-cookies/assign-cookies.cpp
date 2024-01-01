class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0,count=0;
        for(int i=0;i<s.size();i++){
            if(j>=g.size()) return count;
            if(g[j]<= s[i]){
                j++;
                count++;
            }
        }
        return count;
    }
};