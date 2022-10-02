class Trie {
public:    
    char k;
    vector<Trie*> next;
    bool word;
    int index;
    
    Trie() {
        this->next.resize(26, nullptr);
        this->word = false;
        this->index = -1;
    }
    
};

void insert_trie(struct Trie * root, string z, int index) {
    
    if(z.size() == 0) {
        return;
    }
    struct Trie* k = nullptr;
   
    char c = z[0];
    
    if(root->next[c-'a']) {
        k = root->next[c-'a'];
        insert_trie(root->next[c-'a'], z.substr(1), index);
    }else {
        k = new Trie();
        root->next[c-'a'] = k;
        
        insert_trie(root->next[c-'a'], z.substr(1), index);
    }
    if(z.size() == 1) {
        k->word = true;
        k->index = index;
        //cout<<z<<endl;
        //cout<<root->index<<endl;
    }
    
    
}

void search_trie(struct Trie * root,  int x , int y ,vector<vector<char>>& board, unordered_set<string> &res, vector<string>& words) {
    
    if(x < 0 || y < 0 || x > board.size()-1 || y > board[0].size()-1) {
        return;
    }
    
    if(board[x][y] == '#') {
        return;
    }
    
    
    char c = board[x][y];
    board[x][y] = '#';
    if(root->next[c-'a']) {
        if(root->next[c-'a']->word) {
            //cout<<c<<endl;
            res.insert(words[root->next[c-'a']->index]);
        }
        //cout<<c<<endl;
        //cout<<root->index<<endl;
        search_trie(root->next[c-'a'], x+1 , y , board , res , words);
        search_trie(root->next[c-'a'], x-1 , y , board , res , words);
        search_trie(root->next[c-'a'], x , y+1 , board , res , words);
        search_trie(root->next[c-'a'], x , y-1 , board , res , words);
    }
    board[x][y] = c;
    
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
      
        vector<string>  res;
        unordered_set<string> kk;
        Trie * root = new Trie();
        int index = 0;
        
        for(auto &k: words) {        
            insert_trie(root, k, index);
            index++; 
        }
        //if(w.size())
        
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size() ; j++) {
                
                search_trie(root , i , j , board, kk, words);
            }
        }
        for(auto &z:kk) {
            res.push_back(z);
        }
        //sort(res.begin(), res.end());
        return res;
    }
};