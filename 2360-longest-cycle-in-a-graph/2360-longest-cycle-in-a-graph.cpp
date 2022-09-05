class Solution {
public:
    
    //int res = -1;
    
    void dfs(int node, unordered_map<int, int> &vis, int len, vector<int> &path, int & res, vector<int> & edges, unordered_set<int>& atleast_vis) {
        
        if(vis.count(node) || edges[node] == -1 || atleast_vis.count(node)) {
            
            if(vis.count(node)) {
                res = max(res, len - vis[node]);
            }
            return;
        }
        vis.insert({node, len});
        atleast_vis.insert(node);
        path.push_back(node);
        dfs(edges[node], vis, len+1 , path, res, edges, atleast_vis);
        
    }
    
    int longestCycle(vector<int>& edges) {
     
        int res = -1;
        
        unordered_map<int, int> vis;
        unordered_set<int> atleast_vis;
        
        
        vector<int> path;
        
        for(int i = 0; i < edges.size() ; i++) {
            if(atleast_vis.count(i)) {
                continue;
            }
            dfs(i, vis, 0, path, res, edges, atleast_vis);
            vis.erase(vis.begin(), vis.end());
        }
        
        if(res == 0) {
            return -1;
        }
        return res;
    }
};