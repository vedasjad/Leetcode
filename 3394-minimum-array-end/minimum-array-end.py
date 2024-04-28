class Solution:
    def minEnd(self, n: int, x: int) -> int:
        xbits = [0] * 64
        nbits = [0] * 64

        n -= 1

        for i in range(64):
            xbits[i] = x & 1
            x >>= 1
            nbits[i] = n & 1
            n >>= 1

        i = 0
        j = 0
        while i < 64:
            if not xbits[i]:
                xbits[i] = nbits[j]
                j += 1
            i += 1

        ans = 0
        for i in range(64):
            if xbits[i]:
                ans += 2**i

        return ans
