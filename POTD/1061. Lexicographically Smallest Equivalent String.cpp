class Solution {
public:
    void un(int x,int y,vector<int>&parent){
        int a=find(x,parent);
        int b=find(y,parent);
        if(a!=b){
            parent[max(a,b)]=min(a,b);
        }
    }
    int find(int x,vector<int>&parent){
        if(parent[x]==-1){
            return x;
        }
        return parent[x]=find(parent[x],parent);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int>parent(26,-1);
        for(int i=0;i<s1.size();i++){
            un(s1[i]-'a',s2[i]-'a',parent);
        }
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=find(baseStr[i]-'a',parent)+'a';
        }
        return baseStr;
    }
};
