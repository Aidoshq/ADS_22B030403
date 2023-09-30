#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int main () {

    queue <int> n;
    queue <int> b;

    for (int i=0 ; i<10 ; i++) {
        int a;
        cin>> a;
        if(i<5) {
            b.push(a);
        }
        else {
            n.push(a);
        }
    }
    int cnt = 0;
    for (; ;) {
        if (cnt == pow(10, 6)) {
            cout<<"blin nichya";
            return 0;
        }
        if(b.size() == 0 || n.size() == 0) {
            break;
        }
        int nf = n.front();
        int bf = b.front();
        n.pop();
        b.pop();
        if(nf == 0 && bf==9) {
            n.push(bf);
            n.push(nf);
        }
        else if (nf==9 && bf==0) {
            b.push(bf);
            b.push(nf);
        }
        else if(nf>bf) {
            n.push(bf);
            n.push(nf);
        }
        else if (nf<bf) {
            b.push(bf);
            b.push(nf);
        }
        cnt++;
    }

    if (b.size() == 0) {
        cout<<"Nursik"<<" "<< cnt;
    }
    else{
        cout<<"Boris"<<" "<< cnt;
    }

    return 0;
 }