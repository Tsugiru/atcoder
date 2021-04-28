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

const ll MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = 1e7;
const int MX = 100001; //check the limits, dummy

ll p(ll n, ll x) {
    ll ans = 1, cur = n;
    while(x) {
        if(x & 1) ans = (cur * ans) % MOD;
        cur = (cur * cur) % MOD;
        x >>= 1;
    }
    return ans;
}

struct Res {
    ll g, x, y;
};

Res modinv(ll a, ll b) {
    if(b == 0) return {a, 1, 0};
    Res prev = modinv(b, a % b);
    return {prev.g, prev.y, prev.x - a / b * prev.y};
}

ll ncr(ll n, ll r) {
    ll ans = 1, den = 1;
    for(int i = n; i > n - r; i--) ans = (ans * i) % MOD;
    for(int i = 2; i <= r; i++) den = (den * i) % MOD;
    ll inv = (modinv(den, MOD).x + MOD) % MOD;
    return (ans * inv) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, a, b;
    cin >> n >> a >> b;
    ll x = p(2, n);
    ll y = ncr(n, a);
    ll z = ncr(n, b);
    cout << (x - y - z - 1 + 3*MOD) % MOD << endl; 
}