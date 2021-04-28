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
const int MX = 100001; 

struct Res {
    ll g, x, y;
};

Res gcd(ll a, ll b) {
    if(b == 0) return {a, 1, 0};
    Res r = gcd(b, a % b);
    return {r.g, r.y, r.x - r.y * (a / b)};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    vector<ll> a(n);
    unordered_map<int, int> occ;
    for(ll &i : a) {
        cin >> i;
        ll tmp = i;
        for(int j = 2; j * j <= tmp; j++) {
            int cnt = 0;
            while(tmp % j == 0) {
                cnt++;
                tmp /= j;
            }
            occ[j] = max(occ[j], cnt);
        }
        if(tmp) occ[tmp] = max(occ[tmp], 1);
    }

    ll lcm = 1LL;
    for(const auto &p : occ)
        for(int i = 0; i < p.second; i++)
            lcm = (lcm * p.first) % MOD;

    ll sum = 0LL;
    for(ll &i : a) {
        ll iinv = gcd(ll(MOD), i).y;
        iinv = (iinv + MOD) % MOD;
        sum = (sum + (iinv * lcm) % MOD) % MOD;
    }

    cout << sum << endl;
}