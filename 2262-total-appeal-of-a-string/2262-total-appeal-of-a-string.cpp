class Solution {
public:
    long long appealSum(string s) {
        
        
      
        // a -> 1 * 3
        // a b -> 2 * 2   a b c -> b , bc , ab, abc  
        // abc 
        
        // a -> 1* 3
        // ab -> b , ab, b 
        // l
        // l e ->l le lee le 
        // l e e
        vector<int> dp(26, -1);
        long long res = 0;
        int n = s.size();
        for(int i = 0; i < s.size(); i++) {  
         
            res += (n-i)* (i - dp[s[i] - 'a']);
           
            //cout<<res<<endl;
            dp[s[i] - 'a'] = i;
        }
        return res;
    }
};