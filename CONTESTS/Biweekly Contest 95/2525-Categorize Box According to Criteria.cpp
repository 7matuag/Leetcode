class Solution {
public:
    string categorizeBox(int l, int w, int h, int m) {
        bool b=0,hy=0;
        long long int v=(long long int)l*(long long int)w*(long long int)h;
        if(l>=1e4 || w>=1e4 || h>=1e4 || v>=1e9 ){
            b=1;
        }
        if(m>=100){
            hy=1;
        }
        if(b==0 && hy==0){
            return "Neither";
        }
        else if(b==0 && hy==1){
            return "Heavy";
        }
        else if(b==1 && hy==0){
            return "Bulky";
        }
        return "Both";
    }
};
