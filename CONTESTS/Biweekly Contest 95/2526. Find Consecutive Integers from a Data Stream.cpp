class DataStream {
public:
    int val,x;
    DataStream(int value, int k) {
        val=value;
        x=k;
    }
    vector<pair<int,int>>temp;
    bool consec(int num) {
        if(temp.size()==0){
            temp.push_back({num,1});
        }
        else if(temp.back().first==num){
            temp.push_back({num,temp.back().second+1});
        }
        else{
            temp.push_back({num,1});
        }
        if(x<=temp.size() && temp.back().first==val && temp.back().second>=x){
            return 1;
        }
        return 0;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
