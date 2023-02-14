class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int as=a.size()-1,bs=b.size()-1,c=0;
        while(as>=0 || bs>=0 || c!=0){
            int x=0,y=0;
            if(as>=0 && a[as]=='1'){
                x=1;
            }
            as--;
            if(bs>=0 && b[bs]=='1'){
                y=1;
            }
            bs--;
            res=to_string((x+y+c)%2)+res;
            c=(x+y+c)/2;
        }
        return res;
    }
};
