class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> kset;
        long long max_sum = 0, curr_sum = 0;
        vector<int> dup(nums.size(), 0);
        
        
        
        for(int i = 0; i < k && i < nums.size(); i++) {
             if(kset.count(nums[i])) {
                 dup[0] = 1;
             }
             kset[nums[i]]++;
             curr_sum += nums[i];
        }
        
        if(dup[0] == 0) {
            max_sum = max(max_sum, curr_sum);
        }
        
        for(int i = k; i < nums.size(); i++) {
            kset[nums[i-k]]--;
            kset[nums[i]]++;
            if(kset[nums[i-k]] == 0) {
                kset.erase(nums[i-k]);
            }
            curr_sum += nums[i];
            curr_sum -= nums[i-k];
            if(kset.size() < k) {
                dup[i-k+1] = 1;
            }
            
            if(dup[i-k+1] == 0) {
                max_sum = max(max_sum, curr_sum);
            }
            
        }
        
        
        
        
        
     return max_sum;   
    }      
        
    
};