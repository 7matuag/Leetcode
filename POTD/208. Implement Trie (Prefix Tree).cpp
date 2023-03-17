class TrieNode{
public:
    bool ispresent;
    vector<TrieNode*> child;
    TrieNode(){
        for(int i=0;i<26;i++){
            ispresent=0;
            child.push_back(NULL);
        }
    }
};

class Trie {
private:
    TrieNode *root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(!curr->child[idx]){
                curr->child[idx]=new TrieNode();
            }
            curr=curr->child[idx];
        }
        curr->ispresent=1;
    }
    
    bool search(string word) {
        TrieNode *curr=root;
        for(int i=0;i<word.size();i++){
            int idx=word[i]-'a';
            if(!curr->child[idx]){
                return 0;
            }
            curr=curr->child[idx];
        }
        return curr->ispresent;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr=root;
        for(int i=0;i<prefix.size();i++){
            int idx=prefix[i]-'a';
            if(!curr->child[idx]){
                return 0;
            }
            curr=curr->child[idx];
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
