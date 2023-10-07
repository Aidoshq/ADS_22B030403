#include <iostream>
#include <vector>

using namespace std;

int minSubarrayLength(int n, int k, vector<int>& nums) {
    int minLength = n + 1;
    int left = 0, sum = 0;

    for (int right = 0; right < n; ++right) {
        sum += nums[right];

        while (sum >= k) {
            minLength = min(minLength, right - left + 1);
            sum -= nums[left];
            ++left;
        }
    }

    return minLength;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int result = minSubarrayLength(n, k, nums);
    cout << result << endl;

    return 0;
}
