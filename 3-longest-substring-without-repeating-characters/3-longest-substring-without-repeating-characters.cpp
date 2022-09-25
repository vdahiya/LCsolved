class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        
        unordered_map<char, int> k;
        int ans = 0;
        int i = 0;
        int prev = 0;
        for(auto &z: s) {
           
            if(k.count(z)) {
                prev = max(k[z]+1, prev);
            }
            k[z] = i;
            ans = max(i - prev+1, ans);
          
            i++;
        }
        
        return ans;
    }
};