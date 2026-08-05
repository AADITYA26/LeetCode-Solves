class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> TM;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        TM[key].push_back({timestamp , value});
    }
    
    string get(string key, int timestamp) {
        if(TM.find(key)==TM.end()) return "";
        auto& vec = TM[key];
        int start = 0 ;
        int end = vec.size()-1;
        if(timestamp < vec[0].first)return "";
        while(start<=end){
            int mid = start + (end-start)/2;
            if(vec[mid].first == timestamp)return vec[mid].second;
            if(vec[mid].first < timestamp ){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return vec[end].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */