class Solution {
public:
    
    bool satisfy(vector<int>& nums, int d) {
        
        int64_t balance = 0;
        //cout<<d<<endl;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > d) {
                if(nums[i] - d > balance) {
                    return false;
                }else {
                    balance -= (nums[i] -d);
                }
            } else {
                balance += (d -nums[i]);
            }
            
        }
        
        return true;
    }
    
    int minimizeArrayValue(vector<int>& nums) {
     
        int low = 0;
        int high = *max_element(nums.begin(), nums.end());
        
        int ans = INT_MAX;
        
        while(low < high) {
            
            int mid = (low+high)/2;
            
            if(!satisfy(nums, mid)) {
                
                low = mid+1;
            }else {
                high = mid;
            }
        }
        
        return low;
    }
};