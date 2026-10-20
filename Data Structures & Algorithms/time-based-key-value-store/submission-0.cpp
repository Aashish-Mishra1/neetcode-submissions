class TimeMap {
public:
    unordered_map<string,map<int,string>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
        return;
    }
    
    string get(string key, int timestamp) {

        if(mp.find(key)==mp.end()) return "";
        else{
            auto pointer = mp[key].upper_bound(timestamp);

            if(pointer!=mp[key].begin()){
                auto pp = std::prev(pointer);
                return pp->second;
            }

            return "";
        }
    }
};
