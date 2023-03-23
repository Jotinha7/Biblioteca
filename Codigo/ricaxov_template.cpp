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

template<class X, class Y> istream& operator >> (istream& input, pair<X, Y>& var) { input >> var.ff >> var.ss; return input; }
template<class X> istream& operator >> (istream& input, vector<X>& var) { for(auto &x : var) input >> x; return input; }
template<class X, class Y> ostream& operator << (ostream& output, pair<X, Y> const& var) { output << "(" << var.ff << " " << var.ss << ")"; return output; }
template<class X> ostream& operator << (ostream& output, vector<X> const& var) { for(int i = 0; i < sz(var); i++) output << (i > 0 ? " " : "") << var[i]; return output; }
template<class X, class Y> ostream& operator << (ostream& output, map<X, Y> const& var) { bool first = 1; for(auto const &[a, b] : var) { if(first == 0) output << " "; first = 0; output << "{" << a << " : " << b << "}"; } return output; }
template<class X> ostream& operator << (ostream& output, set<X> const& var) { for(auto it = var.begin(); it != var.end(); it++) output << (it != var.begin() ? " " : "") << *it; return output; }

template<class...X> inline void in(X &...x) { ((cin >> x), ...); }
template<class...X> inline void out(X const&...x) { ((cout << x << " "), ...); cout << endl; }

inline void dbg() { cerr << endl; }
template<typename X, typename...Y> inline void dbg(X x, Y...y) { cerr << " " << x; dbg(y...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", dbg(__VA_ARGS__), cerr << endl

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int tt = 1; in(tt); while(tt--) {
    
  }
}
