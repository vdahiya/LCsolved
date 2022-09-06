class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
             
        long long fullsum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                fullsum += nums[i];
                
            }
            nums[i] = abs(nums[i]);
        }
        
        sort(begin(nums), end(nums));
        
        auto comp = [](pair<long long, int> & l, pair<long long, int>& r) {
            if(l.first == r.first) {
                return l.second < r.second;
            }
            return l.first < r.first;
        };
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, decltype(comp)> pq(comp);
        
        //pq.
        pq.push({fullsum - nums[0], 0});
        int l;
        long long res;
        l = 0;
        vector<long long> ans;
        ans.push_back(fullsum);
        
        while(ans.size() < k) {
            auto here = pq.top();
            pq.pop();
            long long sum;
            int index;
            tie(sum, index) = here;
            if(index+1 < nums.size()) {
                 pq.push({sum + nums[index] - nums[index+1], index+1});
                
                 pq.push({sum - nums[index+1], index+1});
                
            }
            ans.push_back(sum);
            
        }
        
        return ans.back();
        
    }
};