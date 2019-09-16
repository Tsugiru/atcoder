#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
int arr[maxN];
int ans[maxN];
vector<int> g[maxN];
int n;
 
int main() {
	cin >> n;
	vector<int> s;
	for (int i = 1; i <= n; ++i) {
		cin >> arr[i];
		while (not s.empty() and arr[s.back()] >= arr[i]) {
			s.pop_back();
		}
		if (not s.empty()) {
			g[s.back()].push_back(i);
		}
		s.push_back(i);
	}
 
	s.clear();
	for (int i = 1; i <= n; ++i) {
		for (int v : g[i]) {
			while (not s.empty() and arr[s.back()] >= arr[v]) {
				s.pop_back();
			}
			if (not s.empty()) {
				ans[v] = arr[s.back()];
			}
			s.push_back(v);
		}
		while (not s.empty() and arr[s.back()] >= arr[i]) {
			s.pop_back();
		}
		s.push_back(i);
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	} cout << endl;
	return 0;
}j