class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0,suba=0,count=0;
        sort(happiness.begin(),happiness.end());
        for(int i=happiness.size()-1;i>=0;i--){
            if(count==k){
                break;
            }
            ans+= max((long long)0,happiness[i]-suba);
            suba++;
            count++;
        }
       return ans;
    }
};