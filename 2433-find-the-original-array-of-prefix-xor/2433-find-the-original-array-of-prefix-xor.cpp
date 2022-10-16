class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        
        
        vector<int> res(pref.size(), 0);
        
        for(int i = pref.size()-1; i >= 1; i--) {
            res[i] = pref[i] ^ pref[i-1];
        }
        
        res[0] = pref[0];
        
        return res;
        
    
};
    
};