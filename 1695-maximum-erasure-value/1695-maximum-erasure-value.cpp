class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        unordered_map<int, int> pos;
        
        int curr_sum = 0, max_sum= 0;
        vector<int> prefix_sum(nums.size(), 0);
        
        for(int i = 0; i < nums.size(); i++) {
            prefix_sum[i] = nums[i] + (i>0?prefix_sum[i-1]:0);  
        }
        
        int prev = -1;
        for(int i = 0; i < nums.size(); i++) {
            
            if(pos.count(nums[i])) {
                prev = max(prev, pos[nums[i]]+1); 
            }
            
            curr_sum = prefix_sum[i] - (prev >=0?prefix_sum[prev-1]:0);
            max_sum = max(curr_sum, max_sum);
            pos[nums[i]] = i;
        }
        
        return max_sum;
        
    }
};