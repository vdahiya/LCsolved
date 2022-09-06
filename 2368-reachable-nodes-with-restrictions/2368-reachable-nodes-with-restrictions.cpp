class Solution {
public:
    
    void dfs(int curr, unordered_set<int> & res, unordered_map<int, vector<int>>& adj, unordered_set<int> &ans) {
        
        if(ans.count(curr)) {
            return;
            //already visited
        }
        ans.insert(curr);
        for(auto&k:adj[curr]) {
            if(res.count(k)) {
               
            }else {
                dfs(k, res, adj, ans);
            }
        }
        
    }
    
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
     
        unordered_map<int, vector<int>> adj;
        unordered_set<int> res;
        unordered_set<int> ans;
        
        for(auto &k:edges) {
            adj[k[0]].push_back(k[1]);
            adj[k[1]].push_back(k[0]);
        }
        
        for(auto &k:restricted) {
            res.insert(k);
        }
        
        dfs(0, res, adj, ans);
        
        return ans.size();
        
    }
};