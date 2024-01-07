class Solution {
public:
    bool check(vector<int>& nums) {
        bool rot = false;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                if (rot)
                    return false;
                else
                    rot = true;
            }
        }
        if(rot) return nums[0]>=nums[nums.size()-1]; 
        return true;
    }
};