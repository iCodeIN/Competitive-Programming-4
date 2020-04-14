#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL 998244353
#define int long long
#define double long double
#define uint unsigned long long
#define deb(x) cerr << #x << " => " << x << "\n"
#define deba(x) cerr << #x << "\n"; for (auto a : x) cerr << a << " "; cerr << "\n";
#define debm(x) cerr << #x << "\n"; for (auto a : x){for(auto b : a) cerr << b << " "; cerr << "\n";}
#define getMat(x, n, m, val) vector<vector<int>> x(n, vector<int> (m, val))
#define fastio ios_base :: sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pout cout << fixed << setprecision(10)
int fastpow(int a, int b, int m) {
    int res = 1; a %= m; while (b > 0) { if (b & 1) res = (res * a) % m;
    a = (a * a) % m; b >>= 1; } return res;}
#define inv(a) fastpow(a, HELL - 2, HELL)
#define size(a) (int) a.size()

int32_t main() { fastio;
	int n; cin >> n;
	int arr[n], brr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}	    
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}
	sort(brr, brr + n);
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] * (n - i) * (i + 1);
	}
	sort(arr, arr + n, greater<int>());
	int res = 0;
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] % HELL;
		res = (res + arr[i] * brr[i]) % HELL;
	}
	cout << res << endl;
    return 0;
}
