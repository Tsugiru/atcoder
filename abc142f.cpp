#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

struct pair_hash {
    size_t operator()(const pii &p) const {
        return p.s ^ p.f;
    }
};

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<cd> vcd;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvl;
typedef unordered_map<int, int> umpii;
typedef unordered_map<ll, ll> umpll;
typedef unordered_set<int> usi;
typedef unordered_set<ll> usll;
typedef unordered_set<pii, pair_hash> uspii;
typedef queue<int> qi;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int inf = 1e9;
const int MX = 100001; //check the limits, dummy

bool bfs(vvi &v, vi &p, int s) {
    queue<int> q;
    q.push(s);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        F0R(i, sz(v[cur])) {
            int nxt = v[cur][i];
            if(nxt == s) {
                p[s] = cur;
                return true;
            }
            if(p[nxt == -1]) {
                p[nxt] = cur;
                q.push(nxt);
            }
        }
    }
    return false;
}

vi construct(int i, vi &p) {
    vi res = {i};
    for(int cur = p[i]; cur != i; cur = p[cur]) {
        res.pb(cur);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;
    vvi v(n, vi());
    F0R(i, m) {
        int x, y; cin >> x >> y; x--; y--;
        v[x].pb(y);
    }

    vi ans;
    F0R(i, n) {
        vi p(n, -1);
        if(bfs(v, p, i)) {
            vi cyc = construct(i, p);
            if(sz(ans) == 0 || sz(cyc) < sz(ans)) ans = cyc;
        }
    }

    if(ans.empty()) cout << -1 << endl;
    else {
        cout << sz(ans) << endl;
        F0R(i, sz(ans)) cout << ans[i] + 1 << endl;
    }
}