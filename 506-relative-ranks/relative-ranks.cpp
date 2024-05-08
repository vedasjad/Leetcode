class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> ranks = score;
        sort(ranks.begin(),ranks.end(),greater<int>());
        unordered_map<int,int> imap;
        for(int i=0;i<ranks.size();i++){
            imap[ranks[i]]=i+1;
        }
        vector<string> finalRanks;
        for(int i=0;i<score.size();i++){
            if(imap[score[i]]==1){
                finalRanks.push_back("Gold Medal");
            }
            else if(imap[score[i]]==2){
                finalRanks.push_back("Silver Medal");
            }
            else if(imap[score[i]]==3){
                finalRanks.push_back("Bronze Medal");
            }
            else{
                finalRanks.push_back(to_string(imap[score[i]]));
            }
        }
        return finalRanks;
    }
};