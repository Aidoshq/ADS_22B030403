#include <iostream>
#include <deque>

using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        deque<int> dq;
        int n;
        cin >> n;
        for (int i = n; i > 0; i--){
            dq.push_front(i);
            int k = i;
            while (k > 0){
                dq.push_front(dq.back());
                dq.pop_back();
                k--;
            }
        }
        for (int i = 0; i < dq.size(); i++){
            cout << dq[i] << ' ';
        }
        cout << '\n';
    }
}