class Solution {
   public:
    int openLock(vector<string>& deadends, string target) {
        string start = "0000";
        unordered_set<string> visited;
        queue<string> qu;
        visited.insert(start);
        if (target == start) return 0;
        for (auto it : deadends) {
            if (it == target || it==start) return -1;
            visited.insert(it);
        }
        qu.push(start);
        int turns = 0;
        while (!qu.empty()) {
            turns++;
            int n = qu.size();
            // cout<<n<<endl;
            for (int i = 0; i < n; i++) {
                string s = qu.front();
                qu.pop();

                for (int i = 0; i < 4; i++) {
                    char ch = s[i];
                    s[i] = char(((ch - '0' - 1 + 10) % 10) + '0');
                    // cout<<s<<endl;
                    if (s == target) return turns;
                    if (visited.count(s)==0) {
                        qu.push(s);
                        visited.insert(s);
                    }
                    s[i] = char(((ch - '0' + 1) % 10) + '0');
                    // cout<<s<<endl;
                    if (s == target) return turns;
                    if (visited.count(s)==0) {
                        qu.push(s);
                        visited.insert(s);
                    }
                    s[i] = ch;
                }
            }
        }
    return -1;
    }
};