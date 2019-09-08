#include <bits/stdc++.h>

using namespace std;

bool check(vector<int> &a, vector<int> &b) {
    int sum = 0;
    for(int i = 0; i < a.size(); i++) {
        sum += abs(a[i] - b[i]) * abs(a[i] - b[i]);
    }
    return (int)sqrt(sum) * (int)sqrt(sum) == sum;
}

int main() {
    int N, D;
    cin >> N >> D;
    vector<vector<int>> pts(N, vector<int>(D));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < D; j++) {
            cin >> pts[i][j];
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(check(pts[i], pts[j])) ans++;
        }
    }
    cout << ans << endl;
}
