#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int best = 0;
    for(int i = 0, k = 0, prev = 0, cur = 0; i < n; i++) {
        cin >> k;
        if(prev != -1 && prev >= k) cur++;
        else cur = 0;
        best = max(best, cur);
        prev = k;
    }
    cout << best << endl;
    return 0;
}