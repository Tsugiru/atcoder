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

bool checkVert(const vector<vector<int>> &v) {
    for(int i = 0; i < 3; i++)
        if(v[i][0] && v[i][0] == v[i][1] && v[i][1] == v[i][2])
            return true;
    return false;
}

bool checkHoriz(const vector<vector<int>> &v) {
    for(int j = 0; j < 3; j++)
        if(v[0][j] && v[0][j] == v[1][j] && v[1][j] == v[2][j])
            return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<int, pair<int, int>> mp;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++) {
            int in; cin >> in;
            mp[in] = {i, j};
        }

    vector<vector<int>> v(3, vector<int>(3, 0));
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int in; cin >> in;
        if(mp.count(in))
            v[mp[in].first][mp[in].second] = 1;
    }

    if(checkHoriz(v) || checkVert(v) 
        || v[0][0] && v[0][0] == v[1][1] && v[1][1] == v[2][2] 
        || v[0][2] && v[0][2] == v[1][1] && v[1][1] == v[2][0])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}