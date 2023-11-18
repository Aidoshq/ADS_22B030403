#include <iostream>
#include <vector>

//qate

using namespace std;

const int p = 31;
const int q = 1e9 + 5;

long long calculateHash(const string &s) {
    long long hash = 0, power = 1;
    for (int i = 0; i < s.size(); i++) {
        hash = (hash + (s[i] - 'a' + 1) * power) % q;
        power = (power * p) % q;
    }
    return hash;
}

int main() {
    int k;
    cin >> k;

    vector<string> strings(k);
    for (int i = 0; i < k; ++i) {
        cin >> strings[i];
    }

    long long referenceHash = calculateHash(strings[0]);
    int maxCommonLength = 0;

    
    for (int length = 1; length <= strings[0].size(); ++length) {
        bool foundCommonSubstring = true;

        
        long long referenceSubstringHash = calculateHash(strings[0].substr(0, length));

        
        for (int i = 1; i < k; ++i) {
            long long currentSubstringHash = calculateHash(strings[i].substr(0, length));
            
            if (currentSubstringHash != referenceSubstringHash) {
                foundCommonSubstring = false;
                break;
            }
        }

       
        if (foundCommonSubstring) {
            maxCommonLength = length;
        }
    }

    
    string result = strings[0].substr(0, maxCommonLength);
    cout << result << endl;

    return 0;
}
