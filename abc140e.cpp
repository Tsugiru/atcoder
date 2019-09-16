#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> v(N, 0), pos(N + 1, 0);
    for (ll i = 0; i < N; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }

    set<ll> s;
    ll ans = 0;
    for (ll i = N; i > 0; i--) {
        auto itr = s.upper_bound(pos[i]);

        ll r1 = itr == s.end() ? N : *(itr++);
        ll r2 = itr == s.end() ? N : *(itr--);
        ll l1 = itr == s.begin() ? -1 : *(--itr);
        ll l2 = itr == s.begin() ? -1 : *(--itr);

        ans += ((l1 - l2) * (r1 - pos[i]) + (r2 - r1) * (pos[i] - l1)) * i;
        s.insert(pos[i]);
    }

    cout << ans << endl;
    return 0;
}