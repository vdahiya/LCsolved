class Solution {
public:
    
    
    
    bool validPartition(vector<int>& nums) {
        
        vector<bool> nn(nums.size(), 0);
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] == nums[i-1] && nums[i-1] == nums[i-2]) {
                nn[i] = true ;  
            }
            if(nums[i] - nums[i-1] == 1 && nums[i-1] - nums[i-2] == 1) {
                nn[i] = true;
            }
        }
        vector<bool> nn1(nums.size(), 0);
        
        for(int i = 1; i < nums.size(); i++) {
             if(nums[i] == nums[i-1]) {
                 nn1[i] = true;
             }
        }
        
        vector<bool> full(nums.size()+1, 0);
        full[0] = true;
        
        for(int i = 0; i < nums.size(); i++) {
            if(i >= 2 && nn[i] == true && full[i-2]) {
                full[i+1] = true;
            }
            if(i >= 1 && nn1[i] == true && full[i-1]) {
                full[i+1] = true;
            }
        }
        
        return full[nn.size()];
        
        
    }
};