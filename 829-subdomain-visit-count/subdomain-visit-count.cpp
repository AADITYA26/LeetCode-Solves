class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string , int> map;
        for(int i = 0 ; i < cpdomains.size() ; i++){
            string str = cpdomains[i];
            string count  ;
            int j;
            for(j = 0 ; j < str.size() ; j++ ){
                if(str[j]==' ')break;
                count+=str[j];
            }
            int c  = stoi(count);
            int k = ++j;
            map[str.substr(j)]+=c;
            for(;k < str.size() ; k++){
                if(str[k]=='.'){
                    map[str.substr(k+1)]+=c;
                }
            }
        }
        vector<string> ans;
        for(auto &p : map){
            string str = to_string(p.second)+' '+p.first;
            ans.push_back(str);
        }
        return ans;
    }
};