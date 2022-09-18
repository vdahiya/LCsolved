struct trie {
    
    char t;
    bool end;
    struct trie*  next[26];
    trie()
    {
        for(int i = 0; i < 26; i++) {
            this->next[i] = nullptr;
        }
        end = false;
    }
    ~trie() {
        for (trie *t : next) delete t;
     }
    
};

void find(struct trie* root, string s, unordered_map<string, unordered_set<char>> &mmap, int &res) {
        if(s.size() == 0) {
            if(root->end == true) {
                res++;
            }
            
        }
        string now = s.substr(0,2);
        for(auto &p:mmap[now]) {
            int t = p -'a';
            if(!root->next[t]) {
                continue;
            }else {
                find(root->next[t], s.substr(2), mmap, res);
            }
        }
}
    
void insert(struct trie* root, string s) {
        if (s.size() == 0) {
           root->end = true;
           return;
        }
        int t = s[0] -'a';
        if(!root->next[t]) {
            root->next[t] = new trie();
        }
        insert(root->next[t], s.substr(1));  
    
    
}

class Encrypter {
public:
    
    
    
    unordered_map<char, string> front;
    unordered_map<string, unordered_set<char>> back;
    unordered_set<string> dict;
    trie* root;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& d) {
        
        for(int i = 0; i < keys.size(); i++) {
            front[keys[i]] = values[i];
            back[values[i]].insert(keys[i]);
        }
        root = new trie();
        for (auto &k:d) {
            dict.insert(k);
            insert(root, k);
        }
        
    }
    
    string encrypt(string word1) {
        
        string res = "";
        for(auto &z:word1) {
            res+= front[z];
        }
        
        return res;
        
    }
    
    int decrypt(string word2) {
        
        int res = 0;
        find(root, word2, back,res);
        return res;
    }
};