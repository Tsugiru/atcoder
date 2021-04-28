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

struct bit {
    vector<int> tree;
    bit(int size) : tree(size + 1, 0) {}

    int read(int x) {
        int ans = 0;
        while(x) {
            ans += tree[x];
            x -= (x & -x);
        }
        return ans;
    }

    void write(int x, int val) {
        while(x < tree.size()) {
            tree[x] += val;
            x += (x & -x);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    string s; cin >> s;

    vector<bit> b(26, bit(n));
    for(int i = 0; i < s.size(); i++)
        b[s[i] - 'a'].write(i + 1, 1);

    int q; cin >> q;
    while(q--) {
        int type;
        cin >> type;

        if(type == 1) {
            int i; char c; cin >> i >> c;
            b[s[i - 1] - 'a'].write(i, -1);
            b[c - 'a'].write(i, 1);
            s[i - 1] = c;
        }
        else {
            int l, r; cin >> l >> r;
            int ans = 0;
            for(int i = 0; i < 26; i++)
                if(b[i].read(r) - b[i].read(l - 1)) ans++;
            cout << ans << endl;
        }
    }
}