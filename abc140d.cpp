#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k;
    cin >> n >> k;
    int flip = 0, ans = 0;
    char cur, prev; cin >> prev;
    for(int i = 1; i < n; i++) {
        char c; cin >> c;
        if(c == prev) ans++;
        else {
            if(flip) {
                flip ^= 1;
                ans++;
            }
            else if(k != 0) {
                flip ^= 1;
                ans++;
                k--;
            }
        }
        prev = c;
    }
    cout << ans << endl;
    return 0;
}