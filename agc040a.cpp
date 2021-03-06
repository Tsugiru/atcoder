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
    size_t operator()(pii x) const {
        return int_hash{}(x.first) ^ (int_hash{}(x.second) << 16);
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
typedef vector<vector<pii>> vvpii;
typedef vector<vector<pll>> vvpll;
typedef unordered_map<int, int, int_hash> umpii;
typedef unordered_map<ll, ll, int_hash> umpll;
typedef unordered_set<int, int_hash> usi;
typedef unordered_set<ll, int_hash> usll;
typedef unordered_set<pii, pair_hash> uspii;
typedef queue<int> qi;
template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = numeric_limits<int>::max();
const int MX = 100001; //check the limits, dummy

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // string s; cin >> s;
    // ll i = s.find_first_of('<'), n = sz(s);
    // ll sum = i != eos ? i * (i + 1) / 2 : n * (n + 1) / 2;
    // for(; i != eos && i < n; i++) {
    //     if(s[i] == '>' && s[i - 1] == '<') {
    //         ll r = i, l = i - 1;
    //         while(r < n && s[r] != '<') r++;
    //         while(l >= 0 && s[l] != '>') l--;
    //         ll a = r - i, b = i - 1 - l;
    //         sum += max(a, b) * (max(a, b) + 1) / 2
    //             + min(a, b) * (min(a, b) - 1) / 2;
    //     }
    // }

    // i = s.find_last_of('>');
    // sum += i != eos ? (n - i - 1) * (n - i) / 2 : n * (n + 1) / 2;
    // cout << sum << endl;

    string s; cin >> s;
    s += "<";
    vector<int> v(s.size());
    for(int i = 0, cur = 0; i < v.size(); i++) {
        if(s[i] == '>') { v[i] = cur; cur = 0; }
        else v[i] = cur++;
    }
    
    for(int i = v.size() - 1, cur = 0; i >= 0; i--) {
        if(s[i] == '<') { cur = 1; }
        else v[i] = max(cur++, v[i]);
    }

    cout << accumulate(begin(v), end(v), 0LL) << endl;
}