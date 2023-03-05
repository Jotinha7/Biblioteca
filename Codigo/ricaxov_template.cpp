#include <bits/stdc++.h>
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define tos to_string
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define entrada freopen("input.txt", "r", stdin);
#define saida freopen("output.txt", "w", stdout);

#define int long long

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const double eps = 1e-9;
const int mod = 998244353;
const int inf = 1000000000;
const double pi = 3.141592653589793;
const ll linf = 1000000000000000000;

template<class T, class U> istream &operator>>(istream &is, pair<T, U> &p) { is >> p.ff >> p.ss; return is; }
template<class T> istream &operator>>(istream &is, vector<T> &v) { for (auto &a : v) is >> a; return is; }
template<class T, class U> ostream &operator<<(ostream &os, pair<T, U> const& p) { os << "(" << p.first << " " << p.second << ")"; return os; }
template<class T> ostream &operator<<(ostream &os, vector<T> const& v) { for (int i = 0; i < v.size(); i++) os << (i ? " " : "") << v[i]; return os; }
template<class T, class U> ostream &operator<<(ostream &os, map<T, U> const& m) { bool first = true; for (auto const& [k, v] : m) { if (!first) os << " "; first = false; os << "{" << k << " : " << v << "}"; } return os; }
template<class T> ostream &operator<<(ostream &os, set<T> const& s) { for (auto it = s.begin(); it != s.end(); it++) os << (it != s.begin() ? " " : "") << *it; return os; }
 
template<class... A> void in(A &...a) { ((cin >> a), ...); }
template<class... A> void out(A const&... a) { ((cout << a << " "), ...); cout << endl; }

void dbg() { cerr << endl; }
template<typename X, typename...Y> void dbg(X x, Y...y) { cerr << ' ' << x; dbg(y...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg(__VA_ARGS__), cerr << endl

auto main() -> signed {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tt = 1; in(tt);
  while(tt--) {


  }
}
