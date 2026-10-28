/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        unordered_map<Node*,Node*>mp;
        Node* start = new Node(node->val);
        mp[node] = start;
        queue<Node*> qu;
        unordered_set<Node*>visited;
        qu.push(node);
        visited.insert(node);

        while(!qu.empty()){
            auto it = qu.front();
            qu.pop();
            
            for(auto neigh:it->neighbors){
                if(visited.find(neigh)==visited.end()){
                    Node* temp = new Node(neigh->val);
                    mp[neigh] = temp;
                    visited.insert(neigh);
                    qu.push(neigh);
                }

                mp[it]->neighbors.push_back(mp[neigh]);
            }
        }
        return start;
        
    }
};
