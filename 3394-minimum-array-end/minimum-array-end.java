class Solution {
    public long minEnd(int n, int x) {
        int[] xbits = new int[64];
        int[] nbits = new int[64];

        n--;

        for (int i = 0; i < 64; i++) {
            xbits[i] = x & 1;
            x >>= 1;
            nbits[i] = n & 1;
            n >>= 1;
        }

        int i = 0;
        int j = 0;
        while (i < 64) {
            if (xbits[i] == 0) {
                xbits[i] = nbits[j++];
            }
            i++;
        }

        long ans = 0;
        for (int k = 0; k < 64; k++) {
            if (xbits[k] != 0) {
                ans += Math.pow(2, k);
            }
        }

        return ans;
    }
}