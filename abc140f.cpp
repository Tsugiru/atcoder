#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;

typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;

typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

int main() {
    int N; cin >> N;

    function<bool(const int &, const int &)> f = [](const int &a, const int &b) { return a > b; };
    multiset<int, function<bool(const int &, const int &)>> s(f);
    for(int i = 0, temp = 0; i < 1 << N; i++) cin >> temp, s.insert(temp);

    bool ok = true;
    vector<int> v(1 << N, 0);
    v[0] = *s.begin();
    s.erase(s.begin());
    for(int i = 0; i < N && ok; i++) {
        for(int j = 0, q = 1 << i; j < 1 << i; j++, q++) {
            auto it = s.upper_bound(v[j]);
            if(it != s.end()) {
                v[q] = *it;
                s.erase(it);
            }
            else {
                ok = false;
                break;
            }
        }
    }

    cout << (ok ? "Yes" : "No") << endl; 
    return 0;
}
