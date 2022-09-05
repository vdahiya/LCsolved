class Solution {
public:
    int maximumRobots(vector<int>& charge, vector<int>& running, long long budget) {
    
        
        set<pair<int, int>> mset;
        int sz = charge.size();
        int left, right;
        left = right=0;
        int res = 0;
        long long curr_sum = 0;
        long long full_sum = 0;
        for(left= 0, right = 0; right < sz;) {
            
            if(mset.size() > 0)
                full_sum = mset.size()*(curr_sum) + (mset.rbegin()->first);
            else
                full_sum = 0;
            
            if(full_sum > budget) {
                
                while(full_sum > budget) {
                    curr_sum -= running[left];
                    mset.erase({charge[left], left});
                    left++;
                    if(mset.size() > 0)
                        full_sum = mset.size()*(curr_sum) + (mset.rbegin()->first);
                    else
                        full_sum = 0;
                }
    
            }else {
                res = max(res, (int)mset.size());
                curr_sum += running[right];
                mset.insert({charge[right], right});
                right++;
                
            }
        }
        
        if(mset.size() > 0)
            full_sum = mset.size()*(curr_sum) + (mset.rbegin()->first);
        if(full_sum <= budget) {
             res = max(res, (int)mset.size());
        }
        
        return res;
    }
};