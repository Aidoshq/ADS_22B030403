#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int value;
    ListNode* next;
    int mode;
    ListNode(int inputValue) {
         this->value = inputValue;
         this->next = nullptr;
         this->mode = 1;
    }
};

struct LinkedList {
     int size;
     ListNode* head;
     LinkedList() {
             this->size = 0;
             this->head = nullptr;
    }

    void push(int val) {
        ListNode* newNode = new ListNode(val);
        if(!this->head) {
            this->head = newNode;
        } else {
            ListNode* tmp = this->head;
            while(tmp) {
                if(val == tmp->value) {
                    tmp->mode++;
                }
                if(!tmp->next) {
                    tmp->next = newNode;
                    tmp = newNode;
                }
                tmp = tmp->next;
            }
        }
        this->size++;
    }

    int getMax() {
        int max = (int)-1e9;
        ListNode* cur = this->head;
        while(cur) {
            if(cur->mode > max) {
                max = cur->mode;
            }
            cur = cur->next;
        }
        return max;
    }

    void solve() {
        ListNode* cur = this->head;
        vector <int> res;
        while(cur) {
            if(cur->mode == getMax()) {
                res.push_back(cur->value);
            }
            cur = cur->next;
        }
        sort(res.begin(), res.end());
        reverse(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
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
        ll->push(x);
    }
    ll->solve();

          return 0;
}