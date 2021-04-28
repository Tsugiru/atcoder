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

struct dsu {
    vector<int> v, szs;

    dsu(int n) : v(n), szs(n, 1) {
        iota(begin(v), end(v), 0);
    }

    int fs(int x) {
        while(v[x] != x) x = v[x];
        return x;
    }

    void ms(int x, int y) {
        int px = fs(x), py = fs(y);
        if(px == py) return;
        if(szs[px] < szs[py]) swap(px, py);
        v[py] = px;
        szs[px] += szs[py];
    }

    int sz(int x) {
        return szs[fs(x)];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    vector<int> cnt(n, 0);
    vector<unordered_set<int>> ss(n);

    dsu dd(n);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        ss[a].insert(b);
        g[b].push_back(a);
        ss[b].insert(a);
        dd.ms(a, b);
    }

    for(int i = 0; i < k; i++) {
        int c, d; cin >> c >> d; c--; d--;
        int pc = dd.fs(c), pd = dd.fs(d);
        if(!ss[c].count(d) && pc == pd) cnt[c]++, cnt[d]++;
    }
    //for(int i = 0; i < n; i++) cout << d.sz(i) << endl;
    //for(int i = 0; i < n; i++) cout << cnt[i] << endl;

    for(int i = 0; i < n; i++) 
        cout << dd.sz(i) - cnt[i] - g[i].size() - 1 << " ";
    cout << '\n';
}