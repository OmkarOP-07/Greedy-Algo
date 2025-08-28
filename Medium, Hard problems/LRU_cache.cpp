#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    // Node for doubly linked list
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
    };

    int capacity;
    unordered_map<int, Node*> cache; // key → node
    Node* head; // most recently used
    Node* tail; // least recently used

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    // helper: remove node
    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // helper: insert node right after head (most recent position)
    void insert(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;
        Node* node = cache[key];
        remove(node);
        insert(node); // move to most recent
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
            cache.erase(key);
        }
        if (cache.size() == capacity) {
            Node* lru = tail->prev;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
        Node* node = new Node(key, value);
        insert(node);
        cache[key] = node;
    }
};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // {1=1}
    lRUCache.put(2, 2); // {1=1, 2=2}
    cout << lRUCache.get(1) << endl; // 1
    lRUCache.put(3, 3); // evicts 2 → {1=1, 3=3}
    cout << lRUCache.get(2) << endl; // -1
    lRUCache.put(4, 4); // evicts 1 → {4=4, 3=3}
    cout << lRUCache.get(1) << endl; // -1
    cout << lRUCache.get(3) << endl; // 3
    cout << lRUCache.get(4) << endl; // 4
}
