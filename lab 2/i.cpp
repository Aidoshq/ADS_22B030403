#include <iostream>

using namespace std;

struct ListNode {
    string value;
    ListNode* next;
    ListNode() {
        this->value = "";
        this->next = nullptr;
    }
    ListNode(string inputValue) {
        this->value = inputValue;
        this->next = nullptr;
    }
};

struct Deque {
    int size;
    ListNode* front;
    ListNode* back;
    Deque() {
        this->size = 0;
        this->front = nullptr;
        this->back = nullptr;
    }

    void add_front(string val) {
        ListNode* newNode = new ListNode(val);
        if(this->size == 0) {
            this->front = newNode;
            this->back = newNode;
        } else {
            newNode->next = this->front;
            this->front = newNode;
        }
        cout << "ok\n";
        this->size++;
    }

    void add_back(string val) {
        ListNode* newNode = new ListNode(val);
        if(this->size == 0) {
            this->front = newNode;
            this->back = newNode;
        } else {
            this->back->next = newNode;
            this->back = newNode;
        }
        cout << "ok\n";
        this->size++;
    }

    void erase_front() {
        if(this->size == 0) {
            cout << "error\n";
        } else {
            cout << this->front->value << "\n";
            this->size--;
            this->front = this->front->next;
        }
    }

    void erase_back() {
        if(this->size == 0) {
            cout << "error\n";
        }
        else if(this->size == 1) {
            cout << this->back->value << "\n";
            this->front = this->back = nullptr;
            this->size--;
        } else {
            this->size--;
            cout << this->back->value << "\n";
            ListNode* cur = this->front;
            while(cur->next != this->back) {
                cur = cur->next;
            }
            cur->next = nullptr;
            this->back = cur;
        }
    }

    void frontBook() {
        if(this->size == 0) {
            cout << "error\n";
        } else {
            cout << this->front->value << "\n";
        }
    }

    void backBook() {
        if(this->size == 0) {
            cout << "error\n";
        } else {
            cout << this->back->value << "\n";
        }
    }

    void eraseAll() {
        this->front = this->back = nullptr;
        this->size = 0;
        cout << "ok\n";
    }
};

int main() {
    string s;
    Deque* d = new Deque();
    while(cin >> s) {
        if(s == "exit") {
            cout << "goodbye\n";
            break;
        }
        else if(s == "add_front") {
            string book;
            cin >> book;
            d->add_front(book);
        }
        else if(s == "add_back") {
            string book;
            cin >> book;
            d->add_back(book);
        }
        else if(s == "erase_front") {
            d->erase_front();
        }
        else if(s == "erase_back") {
            d->erase_back();
        }
        else if(s == "front") {
            d->frontBook();
        }
        else if(s == "back") {
            d->backBook();
        }
        else if(s == "clear") {
            d->eraseAll();
        }
    }

    return 0;
}