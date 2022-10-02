class Solution {
public:
    int minimizeXor(int num1, int num2) {
        // count bits in num2
        int count = 0;
        for(int i = 0; i < 32; i++) {
            
            int x = (1<<i);
            if(x & num2) {
                count++;
            }
        }
        
        //cout<<count<<endl;
        
        uint64_t res = 0;
        set<int> z;
        for(int i = 0; i < 32; i++) {
            
            uint64_t here = 1;
            uint64_t x = (here << (32-i));
            
            if(count == 0) {
                    break;
            }
            if(num1&x) {
                //cout<<i<<endl;
                count--;
                res |=x;
                //cout<<res<<endl;
                z.insert((32-i));
                
            }
            
            
        }
        
        if(count > 0) {
            for(int i = 0; i < 32; i++) {
                if(count == 0) {
                    break;
                }
                if(!z.count(i)) {
                    int x = (1<<i);
                    res |= x;
                    count--;
                }
                
                
            }
            
        }
        
        
        return res;
        
    }
};