#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> v(N, 0), pos(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }

    set<int> s;
    int ans = 0;
    for (int i = N; i > 0; i--) {
        auto itr = s.upper_bound(pos[i]);
        auto itl = itr;

        int r1 = itr == s.end() ? pos[i] : *(itr++);
        int r2 = itr == s.end() ? N : *itr;
        int l1 = itl == s.begin() ? pos[i] : *(--itl);
        int l2 = itl == s.begin() ? -1 : *(--itl);

        if (l1 == pos[i] && l2 == -1) l1 = l2 = pos[i] - 1;
        if (r1 == pos[i] && r2 == N) r1 = r2 = pos[i] + 1;
        ans += ((l1 - l2) * (r1 - pos[i]) + (r2 - r1) * (pos[i] - l1)) * i;
        s.insert(pos[i]);
    }

    cout << ans << endl;
    return 0;
}