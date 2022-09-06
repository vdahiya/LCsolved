class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        
        // 1 4 4 8
        //.1 3 12 4
        // 1 3 4 4 4 4
        //
        // 1 3 13 4
        // 1 3 3 3 3 4.  4
        
        // 1 3 9 4
        // 1 3 4 4 4 4
        int sz = nums.size()-1;
        int prev = nums[nums.size()-1];
        long long ans = 0;
        for( int i = sz -1 ; i >= 0; i--) {
            
            
            if(nums[i] <= prev) {
                prev = nums[i];
                //no divison
            }else {
                int q = nums[i]/prev;
                int rem = nums[i]%prev;
                if(rem == 0) {
                    //perfect divison
                    ans += q-1;
                }else {
                    ans +=q;
                    prev = nums[i]/(q+1);
                }
                //cout<<q<<" "<<prev<<endl;
            }
            
            
        }
        
        
        
        return ans;
    }
};