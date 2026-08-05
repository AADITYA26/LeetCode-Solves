class SnapshotArray {
public:
vector<vector<pair<int,int>>> snapshot;
int snap_id = 0 ; 
    SnapshotArray(int length) {
        snapshot.resize(length);
    }
    
    void set(int index, int val) {
        if(!snapshot[index].empty()&&snapshot[index].back().first == snap_id)snapshot[index].back().second = val;
        else snapshot[index].push_back({snap_id,val});
    }
    
    int snap() {
        snap_id++;
        return snap_id-1;
    }
    
    int get(int index, int snap_id) {
        auto & vec = snapshot[index];
        int start = 0;
        int end  = vec.size()-1;
        while(start<=end){
            int mid = start + (end-start)/2;
            if(vec[mid].first == snap_id)return vec[mid].second;
            else if(vec[mid].first>snap_id)end = mid -1;
            else start = mid + 1;
        }
        if(end==-1)return 0;
        return vec[end].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */