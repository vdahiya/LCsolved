struct comp {
    
      bool operator()(tuple<int, int, int>&l, tuple<int, int, int> &r) {
          
          
          if(get<0>(l) ==  get<0>(r)) {
              return get<1>(l) > get<1>(r); 
          }
          return get<0>(l) > get<0>(r);
          
      }  
};

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
     
        int left = 0;
        int right = costs.size()-1;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, comp> mypq;
        
        for(int i = 0; i < candidates && left <= right ; i++) {
            mypq.push({costs[left], left, 0});
            left++;
            if(left > right) {
                break;
            }
            mypq.push({costs[right], right, 1});
            right--;
        }
        long long res = 0;
        while(k && mypq.size() > 0) {
            int one, two , three;
            auto t = mypq.top();
            tie(one, two, three) = t;
            mypq.pop();
            //cout<<one<<" "<<two<<" "<<three<<endl;
            res += one;
            
            if(left <= right) {
                //insert
                if(three == 0) {
                    mypq.push({costs[left], left, 0});
                    
                    //cout<<"insert"<<" "<<costs[left]<<endl;
                    left++;
                }else {
                    mypq.push({costs[right], right, 1});
                    //cout<<"insert"<<" "<<costs[right]<<endl;
                    right--;
                }
                
                
            }
            k--;
        }
        
        
        
        return res;
    }
};