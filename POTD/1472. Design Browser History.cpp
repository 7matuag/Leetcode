class dll{
public:
    string str;
    dll *next,*prev;
    dll(string url){
        str=url;
        next=NULL;
        prev=NULL;
    }
};
class BrowserHistory {
private:
    dll *curr;
public:
    BrowserHistory(string homepage) {
       curr=new dll(homepage); 
    }
    
    void visit(string url) {
        curr->next=new dll(url);
        curr->next->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(curr->prev && steps){
            curr=curr->prev;
            steps--;
        }
        return curr->str;
    }
    
    string forward(int steps) {
        while(curr->next && steps){
            curr=curr->next;
            steps--;
        }
        return curr->str;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
