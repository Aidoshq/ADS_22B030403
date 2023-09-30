#include <iostream>

using namespace std;

struct ListNode {
    char value;
    ListNode* next;
    bool flag;
    ListNode() {
        this->value = 0;
        this->next = nullptr;
        this->flag = false;
    }
    ListNode(char inputValue) {
        this->value = inputValue;  
        this->next = nullptr;
        this->flag = false;
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

    void addAtTail(char val) {
        ListNode* newNode = new ListNode(val);
        if(!this->tail) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            ListNode* cur = this->head;
            while(cur) {
                if(cur->value == val) {
                    cur->flag = true;
                    return;
                }
                cur = cur->next;
            }
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    void solve() {
        ListNode* cur = this->head;
        while(cur) {
            if(!cur->flag) {
                cout << cur->value << " ";
                return;
            }
            cur = cur->next;
        }
        cout << "-1 ";
    }
};

int main() {
    int n;
    cin >> n;
    while(n--) {
        int t;
        cin >> t;
        LinkedList* ll = new LinkedList();
        while(t--) {
            char c;
            cin >> c;
            ll->addAtTail(c);
            ll->solve();
        }
        cout << endl;
    }

    return 0;
}