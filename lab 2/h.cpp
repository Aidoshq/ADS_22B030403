#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
 
Node* insert(Node* head, Node* node, int p) {
    if(p == 0) {
        node->next = head;
        head = node;
        return head;
    } else {
        Node* cur = head;
        for(int i = 0; i < p - 1; i++) {
            cur = cur->next;
        }
        node->next = cur->next;
        cur->next = node;
        return head;
    } 
}

Node* remove(Node* head, int p) {
    if(p == 0){
        Node * new_head = head -> next;
        delete head;
        return new_head;
    }
    Node* cur = head;
    for(int i = 0; i < p - 1; i++) {
        cur = cur->next;
    }
    Node* d = cur->next;
    cur->next = cur->next->next;
    delete d;
    return head;
}
 
Node* replace(Node* head, int p1, int p2) {
    Node* node = head;
    if(p1 != 0){
        Node * cur = head;
        for(int i = 0; i < p1 - 1; i++) {
            cur = cur->next;
        }
        node = cur->next;
        cur->next = cur->next->next;
    }else{
        node = head;
        head = head->next;
    }
    return insert(head, node, p2);
}
 
Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* cur = head;
    Node* nx = NULL;    
    while(cur){
        nx = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nx;
    }           
    return prev;
}
 
void print(Node* head) {
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}
 
Node* cyclic_left(Node* head, int x) {
    if(x == 0) {
        return head;
    }
    Node* new_head = head;          
    Node* prev = NULL;
    while (x--) {
        prev = new_head;
        new_head = new_head->next;
    }
    Node *tail = new_head;
    while (tail->next) {
        tail = tail->next;
    }
    tail->next = head;
    prev->next = NULL;
    return new_head;
}
 
Node* cyclic_right(Node* head, int x) {
    if(x == 0) {
        return head;
    }
    Node* tail = head;
    int sz = 0;
    while(tail->next){
        sz++;
        tail = tail->next;
    }
    int ind = sz - x;
    Node* last = head;          
    for(int i = 0; i < ind; i++){
        last = last->next;
    }

    Node* new_head = last->next;
    last->next = NULL;
    tail->next = head;
    return new_head;
}
 
int main(){
    Node* head = NULL;
    while (true){
        int command; cin >> command;
        if (command == 0){
            break;
        } else if(command == 1){
            int x, p; 
            cin >> x >> p;
            head = insert(head, new Node(x), p);
        } else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
        } else if (command == 3){
            print(head);
        } else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (command == 5){
            head = reverse(head);
        } else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        } else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}