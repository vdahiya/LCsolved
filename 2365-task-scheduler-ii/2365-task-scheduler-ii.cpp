class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        
        unordered_map<int, long long> kmap;
        long long res = 0;
        for(int i = 0; i < tasks.size(); i++) {
           if(kmap.count(tasks[i])) {
               long long one = 1;
               res += max((kmap[tasks[i]] + space - res + 1) , one);
              
           }else {
               res++;
           }
    
           kmap[tasks[i]] = res;
           
        }
        
        return res;
    }
};