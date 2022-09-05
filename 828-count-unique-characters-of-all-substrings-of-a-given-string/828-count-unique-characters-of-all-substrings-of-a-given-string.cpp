class Solution {
public:
    int uniqueLetterString(string s) {
     
        // a b a
        // 0 2
        // b 1 
        // 2 * 1
        // 2 * 2
        // 2
        
        unordered_map<char, set<int>> mset;
        for(int i = 0; i < s.size() ; i++) {
            mset[s[i]].insert(i);
        }
        int res = 0;
        vector<int> prev(26, -1);
        int n = s.size();
        for(int i = 0; i < s.size() ; i++) {
            
            auto it = mset[s[i]].upper_bound(i);
            if(it == mset[s[i]].end()) {
                res += (n-i) * (i- prev[s[i] - 'A']);
            }else {
                res += (*it-i) * (i- prev[s[i] - 'A']); 
            }
            prev[s[i] - 'A'] = i;
            
        }
         
        return res;
                                  
    }
};