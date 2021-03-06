#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int) 9e18
#define HELL (int) (1e9 + 7)
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

vector<int> getFactors(int n) {
    vector<int> factors = { 1 };
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i * i != n) {
                factors.push_back(n / i);
            }
        }
    }
    return factors;
}

int32_t main() { fastio;
	int n, k;
	cin >> n >> k;
	vector<int> arr(k + 1);
	for (int i = 1; i <= k; i++) {
		arr[i] = fastpow(k / i, n, HELL);
	}
	for (int i = k; i >= 2; i--) {
		vector<int> facts = getFactors(i);
		for (auto f : facts) {
			arr[f] = (arr[f] - arr[i] + HELL) % HELL;
		}
	}
	int res = 0;
	for (int i = 1; i <= k; i++) {
		res = (arr[i] * i + res) % HELL;
	}
	cout << res << endl;
    return 0;
}
