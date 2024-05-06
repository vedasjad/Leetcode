class Solution {
public:
    int tribonacci(int n) {
        int arr[4]= {0,1,1};
        for(int i=3;i<=n;i++){
            arr[i%4] = arr[(i-1)%4]+arr[(i-2)%4]+arr[(i-3)%4];
        }
        return arr[n%4];
    }
};