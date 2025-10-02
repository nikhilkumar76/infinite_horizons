#include <bits/stdc++.h>
using namespace std;

int findMaximumXOR(vector<int>& nums) {
    int maxXOR = 0, mask = 0;
    for (int i = 31; i >= 0; --i) {
        mask |= (1 << i);
        unordered_set<int> s;
        for (int num : nums) s.insert(num & mask);
        int tmp = maxXOR | (1 << i);
        for (int prefix : s) {
            if (s.count(tmp ^ prefix)) {
                maxXOR = tmp;
                break;
            }
        }
    }
    return maxXOR;
}

int main() {
    vector<int> nums = {3,10,5,25,2,8};
    cout << findMaximumXOR(nums) << endl; // 28
    return 0;
}
