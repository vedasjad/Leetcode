class Solution {
public:
    int tribonacci(int n) {
        int arr[39]= {0,1,1};
        for(int i=3;i<=n;i++){
            arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
        }
        return arr[n];
    }

};