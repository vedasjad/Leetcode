class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int start = 0, lenMax = 0;

        for (int i = 0; i < s.length(); ++i) {
            if (charIndexMap.count(s[i])) {
                lenMax = max(i - start, lenMax);
                start = max(charIndexMap[s[i]] + 1, start);
            }
            charIndexMap[s[i]] = i;
        }

        lenMax = max(int(s.length()) - start, lenMax);
        return lenMax;
    }
};