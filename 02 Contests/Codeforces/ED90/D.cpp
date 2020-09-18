#include <bits/stdc++.h>
using namespace std;

#define en "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
#define int long long
#define double long double
#define uint unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fs first
#define sc second
#define size(a) (int) a.size()
#define deb(x) cerr << #x << " => " << x << en
#define debp(a) cerr << #a << " => " <<"("<<a.fs<<", "<<a.sc<<") " << en;
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debpa(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)
#define mul(a, b) ((a % HELL) * (b % HELL)) % HELL

int maxSub(vector<int> &a) {
	int res = 0;
	if (size(a)) {
		res = a[0]; int gl = a[0];
		for (int i = 1; i < size(a); i++) {
			gl = max(a[i], gl + a[i]);
			res = max(res, gl);
		}
	}
	return res;
}

int32_t main() { fastio;
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		vector<int> arr(n);
		for (auto &a : arr) {
			cin >> a;
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (i % 2 == 0) res += arr[i];
		}
		vector<int> t1, t2;
		for (int i = 1; i < n; i += 2) {
			t1.pb(arr[i] - arr[i - 1]);	
		}
		for (int i = 2; i < n; i += 2) {
			t2.pb(arr[i - 1] - arr[i]);
		}
		cout << res + max({ maxSub(t1), maxSub(t2), 0LL }) << endl;
	}
	return 0;
}