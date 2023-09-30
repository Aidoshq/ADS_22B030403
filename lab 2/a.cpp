#include <iostream> 
#include <cmath>

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
        this->size++;
        if(!this->tail) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            this->tail->next = newNode;
            this->tail = newNode;
        }
    }

    int solve(int k) {
        ListNode* cur = this->head;
        int diff = abs(k - cur->value), index = 0, cnt = 1;
        cur = cur->next;
        while(cur) {
            if(diff > abs(k - cur->value)) {
                diff = abs(k - cur->value);
                index = cnt;
            }
            cur = cur->next;
            cnt++;
        }
        return index;
    }
};

int main() {
    int n, k;
    cin >> n;
    LinkedList* ll = new LinkedList();
    while(n--) {
        int x;
        cin >> x;
        ll->addAtTail(x);
    }
    cin >> k;
    cout << ll->solve(k);

    return 0;
}