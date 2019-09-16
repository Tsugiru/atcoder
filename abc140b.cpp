#include <bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n, 0), b(n, 0), c(n - 1, 0);

    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n - 1; i++) cin >> c[i];

    int ans = b[a[0] - 1];
    for(int i = 1; i < n; i++) {
        ans += b[a[i] - 1] + (a[i] == a[i - 1] + 1 ? c[a[i] - 2] : 0);
    }

    cout << ans << endl;
    return 0;
}