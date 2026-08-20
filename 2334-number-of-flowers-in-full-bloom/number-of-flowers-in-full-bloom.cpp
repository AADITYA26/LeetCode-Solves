class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(int i = 0; i < flowers.size(); i++) {
            int start = flowers[i][0];
            int end = flowers[i][1];
            pq.push({start, 1});
            pq.push({end + 1, -1});
        }

        vector<pair<int,int>> p;
        for(int i = 0; i < people.size(); i++)
            p.push_back({people[i], i});

        sort(p.begin(), p.end());

        vector<int> result(people.size());
        int count = 0;

        for(auto person : p) {
            int time = person.first;

            while(!pq.empty() && pq.top().first <= time) {
                count += pq.top().second;
                pq.pop();
            }

            result[person.second] = count;
        }

        return result;
    }
};