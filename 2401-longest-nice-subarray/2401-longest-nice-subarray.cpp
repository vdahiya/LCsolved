class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        
        int res = 1;
        for(int i = 0; i < nums.size(); i++) {
            int full = nums[i];
            for(int j = i+1; j < nums.size(); j++) {
                if(full&nums[j]) {
                    break;
                }else {
                    full |=nums[j];
                    res  = max(res, j-i+1);
                }
            }
        }
        
        return res;
        
    }
};