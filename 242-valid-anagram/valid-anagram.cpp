class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            if (s.length() != t.length()) return false;
            unordered_map<int, int> imap1, imap2;
            for (int i = 0; i < s.length(); i++)
            {
                imap1[s[i]]++;
                imap2[t[i]]++;
            }
            if (imap1.size() != imap2.size()) return false;
            for (auto it: imap1)
            {
                if (it.second != imap2[it.first]) return false;
            }
            return true;
        }
};