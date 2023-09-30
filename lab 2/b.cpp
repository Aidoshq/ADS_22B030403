#include <iostream>

using namespace std;

struct ListNode {
    string value;
    ListNode* next;

    ListNode() {
        this->value = "";
        this->next = nullptr;
    }
    ListNode(string input_value) {
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

    void addAtHead(string value) {
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

    void solve(int k) {
        ListNode* tmp = head;
        while(tmp->next) {
            tmp = tmp->next;
        }
        ListNode* end;
        tmp->next = head;
        while(k--) {
            end = head;
            head = head->next;
        }
        end->next = nullptr;
    }

    void print() {
        ListNode* cur = head;
        while(cur) {
            cout << cur->value << " ";
            cur = cur->next;
        }
    }
};

int main() {
    LinkedList* ll = new LinkedList();
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ll->addAtHead(s);
    }
    ll->solve(k);
    ll->print();

    return 0;
}