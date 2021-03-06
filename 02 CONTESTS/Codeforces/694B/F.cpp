#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(aa) (int) aa.size()
#define deb(xx) cerr << #xx << " => " << xx << "\n"
#define debp(aa) cerr << #aa << " => " <<"("<<aa.fs<<", "<<aa.sc<<") " << "\n";
#define deba(xx) cerr<<#xx<<"\n";for (auto z : xx) cerr << z << " "; cerr << "\n";
#define debpa(xx) cerr<<#xx<<"\n";for (auto z : xx)cerr<<"("<<z.fs<<", "<<z.sc<<") "; cerr << "\n";
#define debm(xx) cerr<<#xx<<"\n";for (auto z : xx){for(auto b : z) cerr << b << " "; cerr << "\n";}
#define getMat(xx, nn, mm, vall) vector<vector<int>> xx(nn, vector<int> (mm, vall))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL
#define _all(aa) aa.begin(), aa.end()

vector<vector<int>> adj;
vector<int> res;
vector<int> vis;

void dfs(int u) {
	if (vis[u] == 0) {
		res.pb(u);
		for (auto x : adj[u]) {
			vis[x] = -1;
		}
	}
	vis[u] = 1;
	for (auto x : adj[u]) {
		if (vis[x] != 1) {
			dfs(x);
		}
	}
}

signed main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		adj = vector<vector<int>>(n + 1);
		res.clear();
		vis = vector<int>(n + 1, 0);
		int u, v;
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1);
		int count = 0;
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 1) count++;
		}
		if (count == n) {
			cout << "YES" << endl;
			cout << size(res) << endl;
			for (auto r : res) {
				cout << r << " ";
			} cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}