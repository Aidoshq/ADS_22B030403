#include <iostream>

#include <algorithm>

using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    ListNode() {
        this->value = 0;
        this->next = nullptr;
    }  
    ListNode(int inputValue) {
        this->value = inputValue;
        this->next = nullptr;
    }
};

struct LinkedList {
    int size;
    ListNode* head;
    ListNode* tail;
    LinkedList() {
        this->size = 0;
        this->head = nullptr;
        this->tail = nullptr;
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        if(!this->tail) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
        this->size++;
    }

    int solve() {
        ListNode* cur = this->head;
        int maxSoFar = -1e9, maxEndingHere = 0;
        while(cur) {
            maxEndingHere += cur->value;
            maxEndingHere = max(maxEndingHere, cur->value);
            maxSoFar = max(maxSoFar, maxEndingHere);
            cur = cur->next;
        }
        return maxSoFar;
    }
};

int main() {
    int n;
    cin >> n;

    LinkedList* ll = new LinkedList();
    while(n--) {
        int x;
        cin >> x;
        ll->addAtTail(x);
    }
    cout << ll->solve();

    return 0;
}