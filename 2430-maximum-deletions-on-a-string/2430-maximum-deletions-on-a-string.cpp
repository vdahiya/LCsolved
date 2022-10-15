class Solution {
public:
    int dp[40001];
    
    int get(string &s, int index) {
        
        
        if(dp[index] != -1) {
            return dp[index];
        }
        
        int res = 1;
        for(int i = 1; i <= s.size() -index; i++) {
            //if (s.compare(i, len, s, i + len, len) == 0)
            //if(s.substr(index, i) == s.substr(i+ index, i)) {
            if (s.compare(index, i, s, i+index, i) == 0) {
                res = max ( res , 1+ get(s, index+i));
            }
        }
        
        dp[index] = res;
        
        return res;
        
    }
    
    int deleteString(string s) {
        
        memset(dp, -1, sizeof(dp)); 
        int l = get(s, 0);
        
        return l;
        
    }
};