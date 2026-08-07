class Solution {
public:
    bool isOnehour(string a , string b){
        int hour1 =stoi( a.substr(0,2));
        int min1 = stoi(a.substr(3,2));
        int hour2 = stoi(b.substr(0,2));
        int min2 = stoi(b.substr(3,2));
        int elaspedTime = -1*(60*hour1+min1)+60*hour2+min2;
        return elaspedTime<=60;
    }
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        unordered_map<string , vector<string>> map ;//name use 
        for(int i = 0 ; i < keyName.size() ; i++){
            map[keyName[i]].push_back(keyTime[i]);
        }
        vector<string> ans;
        for(auto & p : map){
            vector<string> &times = p.second;
            if(times.size()<3) continue;
            sort(times.begin() , times.end());
            for(int i = 0 ; i < times.size() ; i++){
                if(i > times.size()-3)break;
                if(isOnehour(times[i] , times[i+1])&&isOnehour(times[i], times[i+2])){
                    ans.push_back(p.first);
                    break;
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};