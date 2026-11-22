#include <unordered_map>
using namespace std;

class LRUCache {
private:
    struct Node {
        int key, val;
        Node *prev, *next;
        Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    Node *head, *tail;
    unordered_map<int, Node*> mp;

    void unlink(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addFront(Node* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        mp.reserve(capacity); // Pre-allocates hash buckets to prevent expensive rehashing
    }

    ~LRUCache() {
        Node* curr = head;
        while (curr) {
            Node* nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it == mp.end()) return -1;

        Node* node = it->second;
        unlink(node);
        addFront(node);
        return node->val;
    }

    void put(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            Node* node = it->second;
            node->val = value;
            unlink(node);
            addFront(node);
            return;
        }

        if (mp.size() == cap) {
            // Reuse the evicted LRU node instead of deleting and calling `new` again
            Node* lru = tail->prev;
            mp.erase(lru->key);
            unlink(lru);

            lru->key = key;
            lru->val = value;
            mp[key] = lru;
            addFront(lru);
        } else {
            Node* node = new Node(key, value);
            mp[key] = node;
            addFront(node);
        }
    }
};
