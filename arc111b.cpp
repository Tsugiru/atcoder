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

pair<int, bool> dfs(int a, int prev, unordered_set<int> &s, 
    unordered_map<int, vector<int>> &mp) {
        if(s.count(a)) {
            return {0, false};
        }
        pair<int, bool> res{1, true};
        s.insert(a);
        for(int next : mp[a]) {
            if(next != prev) {
                auto [ret_cnt, ret_cycle] = dfs(next, a, s, mp);
                res.first += ret_cnt;
                res.second &= ret_cycle;
            }
        }
        return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; cin >> n;
    unordered_map<int, vector<int>> g;
    for(int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    unordered_set<int> vis;
    int res = 0;
    for(const auto &[a, b] : g) {
        const auto [num, cyc] = dfs(a, -1, vis, g);
        res += num - cyc;
    }

    cout << res << endl;
}