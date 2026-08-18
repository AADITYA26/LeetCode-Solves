class Solution {
public:
    int countCollisions(string directions) {
        int count = 0;
        int n = directions.size();
        int l = 0 ;
        int r = n-1;
        while(l < n && directions[l]=='L')l++;
        while(r >= 0 && directions[r] == 'R')r--;
        for(int i = l ; i <= r ; i++){
            if(directions[i]=='S')continue;
            count++;
        }
        return count;
    }
};