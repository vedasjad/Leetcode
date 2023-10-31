class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> numsMap;
        vector<pair<int,int>> numsCounts;
        vector<int> kNums;
        for(int num:nums){
            numsMap[num]++;
        }
        for(auto it:numsMap){
            pair<int,int> numCount= make_pair(it.second,it.first);
            numsCounts.push_back(numCount);
        }
        sort(numsCounts.begin(),numsCounts.end());
        reverse(numsCounts.begin(),numsCounts.end());
        for(int i=0;i< k;i++){
            kNums.push_back(numsCounts[i].second);
        }
        return kNums;
    }
};