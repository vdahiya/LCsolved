class Solution {
public:
    int longestIdealString(string s, int k) {
        //
        vector<int> len(s.size()+1, 0);
        int res = 0;
        vector<int> alpha(26, 0);
        for(int i = 0; i < s.size(); i++) {
            
            int now = s[i] -'a';
            len[i] = max(alpha[now]+1, len[i]);
            alpha[now] = max(len[i], alpha[now]);
            
            res = max( len[i], res);
            
            for(int j = 1; j <= k; j++) {
                    if(now+j < 26) {
                        len[i] = max(alpha[now+j]+1, len[i]);
                        alpha[s[i]-'a'] = max(len[i], alpha[s[i]-'a']) ;
                        res = max(len[i], res);
                    }
                    if(now -j >= 0) {
                        len[i] = max(alpha[now-j]+1, len[i]);
                        alpha[s[i]-'a'] = max(len[i], alpha[s[i]-'a']) ;
                        res = max(len[i], res);
                    }
                    
                }
            
        }
        
        
        return res;
        
    }
};