class Solution {
public:

    int minAnagramLength(string s) {
        int len = 1, n = s.size();
        unordered_map<char, int> imaps[n];
        unordered_map<char, int> imap;
        for (int i = 0; i < n; i++) {
            imap[s[i]]++;
            imaps[i] = imap;
        }
        while (len <= n) {
            if(n%len){
                len++;
                continue;
            }
            int first = 0, end = n - len;
            unordered_map<char, int> emap = imaps[n - 1], fmap = imaps[len - 1];
            if (end > 0) {
                for (auto it : imaps[end - 1]) {
                    emap[it.first] -= it.second;
                }
            }
            bool flag = false;
            for (auto it : emap) {
                if (!fmap.count(it.first) || it.second != fmap[it.first]) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                unordered_map<char, int> smap;
                for (int i = len; i < n; i += len) {
                    if (i + len - 1 >= n) {
                        flag = true;
                        break;
                    };
                    smap = imaps[i + len - 1];
                    for (auto it : imaps[i - 1]) {
                        smap[it.first] -= it.second;
                    }
                    for (auto it : smap) {
                        if (!fmap.count(it.first) ||
                            it.second != fmap[it.first]) {
                            flag = true;
                            break;
                        }
                    }
                }
                if (!flag)
                    return len;
            }
            len++;
        }
        return len;
    }
};