class Solution {
public:
    string largestPalindromic(string num) {
        if(num.size() == 0) {
            return "0";
        }
        
        unordered_map<char, int> mmap;
        
        for(int i = 0; i < num.size(); i++) {
            
                mmap[num[i]]++;
        }
        int now = 0;
        string res;
        string mid = "";
        for(int i = 9;i > 0; i--) {
            char here = '0' + i;
            if(mmap[here] >= 2) {
                for(int i = 0; i < mmap[here]/2; i++) {
                    res += here;
                }
            }
            if(mid.size() == 0 && mmap[here]%2) {
                mid+= here;
            }
        }
        
        if(res.size() > 0) {
            char here = '0';
            if(mmap[here] >= 2) {
                for(int i = 0; i < mmap[here]/2; i++) {
                    res += here;
                }
            }
        }
        
        if(mid.size() == 0 && mmap['0']%2) {
                mid+= '0';
        }
        if(res.size() == 0 and mid.size() == 0 && mmap['0']%2 == 0) {
            mid+='0';
        }
        string rev = res;
        reverse(rev.begin(), rev.end());
        string ans = res + mid + rev;
        
        
        return ans;
        
    }
};