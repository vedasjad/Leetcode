class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> xbits(64,0),nbits(64,0);
        n--;
        for(int i=0;i<64;i++){
            xbits[i]=x&1;
            x>>=1;
            nbits[i]=n&1;
            n>>=1;
        }
        int i=0,j=0;
        while(i<64){
            if(!xbits[i]){
                xbits[i]=nbits[j++];
            }
            i++;
        }
        long long ans=0;
        for(int i=0;i<64;i++){
            if(xbits[i]){
                ans+=(long long)pow(2,i);
            }
        }
        return ans;
    }
};