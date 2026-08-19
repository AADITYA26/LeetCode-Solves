class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> temp;

        for(int x : asteroids) {
            if(x > 0)temp.push(x);
            else {
                while(!temp.empty() && temp.top() > 0 && temp.top() < abs(x))temp.pop();
                if(temp.empty() || temp.top() < 0)temp.push(x);
                else if(temp.top() == abs(x))temp.pop();
            }
        }
        vector<int> ans;
        while(!temp.empty()) {
            ans.push_back(temp.top());
            temp.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};