#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int prev = INT_MAX, cur = 0, ans = 0;
    for(int i = 0; i < n - 1; i++) {
        cin >> cur;
        ans += min(cur, prev);
        prev = cur;
    }
    cout << ans + cur << endl;
    return 0;
}