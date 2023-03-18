class Solution {
public:
    int distMoney(int money, int children) {
        if(children>money){
            return -1;
        }
        if(children==1 && money==4){
            return -1;
        }
        if(money<8){
            return 0;
        }
        money=money-children;
        int count=0,i=0;
        while(i<children){
            if(i==children-1){
                if(money==3){
                    count--;
                }
                else if(money==7){
                    count++;
                }
            }
            else{
                if(money>=7){
                    money-=7;
                    count++;
                }
                else{
                    money=0;   
                }
            }
            i++;
        }
        return count;
    }
};
