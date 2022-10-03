class Solution {
public:
    
    struct trie {
       
        vector<shared_ptr<trie>> next;
        int score;
       
        trie() {
            next.resize(26, nullptr);          
            this->score = 0;
        }
    };
    
    void insert(string &s, shared_ptr<trie> & root) {
        
        shared_ptr<trie> it = root;
        
        
        for(int i = 0; i < s.size(); i++) {
            if(!it->next[s[i]-'a']) {
                auto here = make_shared<trie>();
                it->next[s[i]-'a'] = here;
            }
            it->next[s[i]-'a']->score+=1;
            it = it->next[s[i]-'a'];
        }
        
        
      
    }
    
    int get_score(shared_ptr<trie> & root, string &s) {
        
        int sc= 0;
        shared_ptr<trie> next = root;
        
        for(int i = 0; i < s.size(); i++) {
            
            sc += next->next[s[i]-'a']->score;
            next = next->next[s[i]-'a'];
        }
        return sc;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        
        shared_ptr<trie> root = make_shared<trie>();
        //cout<<root<<endl;
        shared_ptr<trie> &orig = root;
        for(auto &k:words) {
            //cout<<root<<endl;
            insert(k, root);
        }
        
        vector<int> res;
        
        for(auto &k:words) {
            res.push_back(get_score(root, k));
        }
        
        
        return res;
    }
};