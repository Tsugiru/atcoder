#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef long long ll;

struct int_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct pair_hash {
    size_t operator()(pair<int, int> x) const {
        return int_hash{}(x.first) ^ (int_hash{}(x.second) << 16);
    }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = 1e7;
const int MX = 100001; //check the limits, dummy

ll check_neg(const vector<ll> &a, const ll k, const ll x, const ll split) {
    ll sum = 0LL;
    ll n = a.size();

    for(ll i = 0, j = n - 1; i < split; i++) {
        while(j >= split && a[i] * a[j] < x) j--;
        sum += n - j - 1;
    }

    return sum;
}

ll check_pos(const vector<ll> &a, const ll k, const ll x, const ll split) {
    ll sum = 0LL;
    ll n = a.size();

    for(ll i = 0, j = split - 1; i < j; i++) {
        while(j > i && a[i] * a[j] >= x) j--;
        sum += j - i;
    }

    for(ll i = split, j = n - 1; i < j; i++) {
        while(j > i && a[i] * a[j] >= x) j--;
        sum += j - i;
    }

    return sum;
}

ll check(const vector<ll> &a, const ll k, const ll x, const ll split) {
    ll n = a.size();
    if(k <= split * (n - split)) return check_neg(a, k, x, split);
    else return check_pos(a, k, x, split) + split * (n - split);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(ll &i : a) cin >> i;
    sort(begin(a), end(a));
    ll split = find_if(begin(a), end(a), [](ll i){return i >= 0;}) - begin(a);
    reverse(begin(a), begin(a) + split);

    ll lo = -1e18, hi = 1e18; hi++;
    while(hi - lo > 1) {
        ll mid = (hi + lo) / 2;
        if(check(a, k, mid, split) < k) lo = mid;
        else hi = mid;
    }

    cout << lo << endl;
}