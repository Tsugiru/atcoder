#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;

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
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int inf = 1e9;
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; cin >> n >> m;
    vvi v(m, vi());
    vi c(m, 0);
    int t = 0;
    F0R(i, m){
        int a, b; cin >> a >> b;
        c[i] = a;
        F0R(j, b) {
            int x; cin >> x; x--;
            t = t | (1 << x);
            v[i].pb(x);    
        }
    }

    int q = 1 << n;
    if(t != q - 1) {
        cout << -1 << endl;
        return 0;
    }

    vvi dp(m + 1, vi(q, inf));
    F0R(i, m) dp[i][0] = 0;
    FOR(i, 1, m + 1) {
        F0R(j, q) {
            int r = j;
            for(int x : v[i - 1]) {
                if(r & (1 << x)) r -= 1 << x;
            }
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], dp[i][r] + c[i - 1]);
        }
    }

    cout << dp[m][q - 1] << endl;
}