#include <iostream>
#include <algorithm>

using namespace std;

 int solve(string s, string t) {
  int n = t.size(), m = s.size(), cnt = 0, i = 0;
  bool flag = false;
  while(i < m) {
    int j = i, k = 0, cnt = 1;
    while (k < n && s[j] == t[k]) {
      if (k == n - 1) {
        flag = true;
        break;
      }
      j = (j + 1) % m;
      if (!j) cnt++;
      k++;
    }
    if (flag) {
        return cnt;
    }
    i++;
  }
  return -1;
}


int main() {
    string s, t;
    cin >> s >> t;

    cout << solve(s, t) << "\n";

    return 0;
}