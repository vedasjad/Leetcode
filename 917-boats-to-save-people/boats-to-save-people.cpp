class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0,j=people.size()-1,num=0;
        while(i<=j){
            if(people[j]+people[i]>limit){
                num++;
                j--;
            }
            else{
                num++;
                j--;
                i++;
            }
        }
        return num;
    }
};