
struct node {
    
    vector<shared_ptr<node>> next;
    int sum;
    char t;
public:
    node(char s):t(s){
        next.resize(26, nullptr);
        sum = 0;
    }
    void insert(shared_ptr<node> root, string s, int old, int n_val, bool seen);

};


void node::insert(shared_ptr<node> root, string s, int old, int n_val, bool seen) {
    
    if(s.size() == 0) {
        return;
    }
    char t = s[0];
   
    if(root->next[t-'a']) {
        if(!seen) {
            root->next[t-'a']->sum += n_val;
        }else {
            root->next[t-'a']->sum += n_val;
            root->next[t-'a']->sum -= old;
        }
       
        insert(root->next[t-'a'], s.substr(1), old,n_val, seen);
        return;
    }
    root->next[t-'a'] = std::make_shared<node>(node(s[0]));
    root->next[t-'a']->t = s[0];
    if(!seen) {
            root->next[t-'a']->sum += n_val;
        }else {
            root->next[t-'a']->sum += n_val;
            root->next[t-'a']->sum -= old;
    }
    
    insert(root->next[t-'a'], s.substr(1), old, n_val, seen);  
}


int get(shared_ptr<node> root, string prefix) {
    
    if(prefix.size() == 0) {
        if(!root) {
            return 0;
        }else {
            return root->sum;
        }
    }
    if(!root || prefix.size() == 0) {
        return 0;
    }
    char t = prefix[0];
    return get(root->next[t-'a'], prefix.substr(1));
}




class MapSum {
public:
    shared_ptr<node> root;
    unordered_map<string, int> mmap;
    MapSum() {
        root = make_shared<node>(node('#'));
    }
    
    void insert(string key, int val) {
        if(!mmap.count(key)) {
            root->insert(root, key, 0, val, false);
        }else {
            root->insert(root, key, mmap[key], val, true);
        }
        mmap[key] = val;
        
    }
    
    int sum(string prefix) {
        if(prefix.size() == 0)
            return 0;
        
        char t = prefix[0];
        
        int s = get(root->next[t-'a'], prefix.substr(1));
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */