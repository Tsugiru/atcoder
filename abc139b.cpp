#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b; cin >> a >> b;
    if(b == 1) {
        cout << 0 << endl;
        return 0;
    }
    b = max(b - a, 0);
    cout << b / (a - 1) + 1 + (b % (a - 1) != 0) << endl;        
    return 0;
}