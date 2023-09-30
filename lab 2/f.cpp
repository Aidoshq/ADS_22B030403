#include <iostream>

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

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        this->size++;
        if(!this->head) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            newNode->next = this->head;
            this->head = newNode;
        }
    }

    void addAtTail(int val) {
        ListNode* newNode = new ListNode(val);
        this->size++;
        if(!this->tail) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    void addAtIndex(int index, int data) {
        if(index == 0) {
            this->addAtHead(data);
        } else if(index == this->size) {
            this->addAtTail(data);
        } else {
            ListNode* cur = this->head;
            ListNode* newNode = new ListNode(data);
            for(int i = 0; i < index - 1; i++) {
                cur = cur->next;
            }
            newNode->next = cur->next;
            cur->next = newNode;
            this->size++;
        }
    }

    void print() {
        ListNode* cur = this->head;
        while(cur) {
            cout << cur->value << " ";
            cur = cur->next;
        }
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
    int data, position;
    cin >> data >> position;
    ll->addAtIndex(position, data);
    ll->print();

    return 0;
}