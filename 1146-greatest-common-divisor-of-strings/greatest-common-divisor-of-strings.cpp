class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int x = gcd(n ,  m);
        if(str1+str2==str2+str1)return str1.substr(0,x);
        else return "";
        
    }
};