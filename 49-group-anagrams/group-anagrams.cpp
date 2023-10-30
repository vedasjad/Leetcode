class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &strs)
        {
            unordered_map<string, vector < string>> imap;
            for (string str: strs)
            {
                string tempStr = str;
                sort(tempStr.begin(), tempStr.end());
                imap[tempStr].push_back(str);
            }
            vector<vector < string>> anagrams;
            for (auto it: imap)
            {
                anagrams.push_back(it.second);
            }
            return anagrams;
        }
};