class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        
        
        set<int> mset;
        uint64_t sum = 0;
        for(auto p:damage) {
            mset.insert(p);
            sum+=p;
        }
        // 1 2 2 3 4
        auto k = mset.upper_bound(armor);
        int diff = 0;
        if(k == mset.end()) {
            diff = *(prev(k,1));
        }else {
            diff = armor;
        }
        
        sum -= diff;
        
        return sum+1;
    }
};