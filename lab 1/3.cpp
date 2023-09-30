#include <iostream>

using namespace std;

bool isPrime(int num){
    if (num <= 1){
        return false;
    }
    for (int i = 2; i * i <= num; i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    if (n <= 0){
        cout << "Try again" << endl;
        return 1;
    }

    int counter = 0;
    int num = 2;

    while (counter < n){
        if (isPrime(num)) {
            counter++;
            if (counter == n){
                cout << num << endl;
                break;
            }
        }
        num++;
    }

    return 0;
}

// f