#include <iostream>

using namespace std;

struct ListNode {
    int value;
    ListNode* next;

    ListNode() {
        this->value = 0;
        this->next = nullptr;
    }
    ListNode(int input_value) {
        this->value = input_value;
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

    void addAtHead(int value) {
        ListNode* new_node = new ListNode(value);
        this->size++;
        if(!this->tail) {
            this->head = new_node;
            this->tail = new_node;
        } else {
            this->tail->next = new_node;
            this->tail = new_node;
        }
    }

    void solve() {
        ListNode* cur = head;
        int cnt = 0;
        while(cur) {
            if(cnt % 2 == 0) {
                cout << cur->value << " ";
            }
            cnt++;
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
        ll->addAtHead(x);
    }
    ll->solve();

    return 0;
}