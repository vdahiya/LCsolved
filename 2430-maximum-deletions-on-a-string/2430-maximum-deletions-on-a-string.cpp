class Solution {
public:
    int dp[40001];
    
    int get(string &s, int index, vector<vector<int>> &check) {
        
        
        if(dp[index] != -1) {
            return dp[index];
        }
        
        int res = 1;
        for(int i = 1; i <= s.size() -index; i++) {
            //if (s.compare(i, len, s, i + len, len) == 0)
            //if(s.substr(index, i) == s.substr(i+ index, i)) {
            if (s.compare(index, i, s, i+index, i) == 0) {
                res = max ( res , 1+ get(s, index+i, check));
            }
        }
        
        dp[index] = res;
        
        return res;
        
    }
    
    int deleteString(string s) {
        
        memset(dp, -1, sizeof(dp));
        
        vector<vector<int>> check;
        /*for(auto &z:check) {
            z.resize(s.size(), 0);
        }*/
        
        //memset(check, 0, sizeof(check));
        
        
        
        int l = get(s, 0, check);
        
        return l;
        
    }
};