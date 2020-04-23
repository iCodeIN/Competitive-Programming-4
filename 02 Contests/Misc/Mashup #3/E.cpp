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
#define deba(x) cerr << #x << en; for (auto a : x) cerr << a << " "; cerr << en;
#define debp(x) cerr << #x << en; for (auto a : x)cerr<<"("<<a.fs<<", "<<a.sc<<") "; cerr << en;
#define debm(x) cerr << #x << en; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << en;}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m = HELL) { int res = 1; a %= m;
while (b > 0) { if (b & 1) res = (res * a) % m; a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2)

int32_t main() { fastio;
	int n, k;
	cin >> n >> k;
	int x, middle = n, side = 2*n, one = 0, two = 0;
	for (int i = 0; i < k; i++) {
		cin >> x;
		while (x >= 3) {
			if (middle) {
				x -= 4;
				middle--;
			} else if (side) {
				x -= 2;
				side--;
			} else {
				cout << "NO" << endl;
				return 0;
			}
		}
		if (x == 1) one++;
		else if (x == 2) two++;
	}
	int only_one = 0;
	while (two) {
		if (side) {
			two--; side--;
		} else if (middle) {
			two--; middle--; only_one++;
		} else {
			two--; one += 2;
		}
	}
	one = max(0LL, one - only_one);
	if (one > (side + 2*middle)) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
	}
	return 0;
}
