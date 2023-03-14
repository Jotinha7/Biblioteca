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

class Hash { // dont forget to use #define int long long
  public:
		int qnt;
		string str;
		vector<int> base = {31, 37}, mod = {1000000007, 1000000009}; // bases and mods
    vector<vector<int>> hashes, inv_pow;
    int binpow(int a, int b, int m) {
      a %= m;
      int x = 1;
      while (b > 0) {
        if (b & 1) x = x * a % m;
        a = a * a % m; b >>= 1;
      }
      return x;
    }
    int inverse(int x, int m) {
      return binpow(x, m - 2, m);
    }
    Hash(const string& word, const int& num) {
			qnt = num, str = word;
			hashes.assign(qnt, vector<int>(sz(str), 0)); // hashing using prime nums 
			for(int i = 0; i < qnt; i++) {
				int pt = 1, h = 0;
				for(int j = 0; j < sz(str); j++) {
					h = (h + str[j] * pt) % mod[i];
					pt = (pt * base[i]) % mod[i];
					hashes[i][j] = h;
				}
			}
      int inv = 1; // inverse modulo magic :D
      while(inv < sz(str)) { inv <<= 1; }
      inv_pow.assign(qnt, vector<int>(inv, -1));
      for(int i = 0; i < qnt; i++) {
        inv_pow[i][inv - 1] = inverse(binpow(base[i], inv - 1, mod[i]), mod[i]);
      }
      for(int i = 0; i < qnt; i++) {
        for(int j = inv - 2; j >= 0 && inv_pow[i][j] == -1; j--) {
          inv_pow[i][j] = (inv_pow[i][j + 1] * base[i]) % mod[i];
        }
      }
		}
		vector<int> get_hash(const int& l, const int& r) { // range hashing using inverse modulo and preffix diffs
      vector<int> multiple_hash;
			if(l == 0) {
        for(int i = 0; i < qnt; i++) {
          multiple_hash.push_back(hashes[i][r]);
        }
        return multiple_hash;
      }
      for(int i = 0; i < qnt; i++) {
        int range_hash = hashes[i][r] - hashes[i][l - 1];
        range_hash += (range_hash < 0 ? mod[i] : 0);
        range_hash = (range_hash * inv_pow[i][l]) % mod[i];
        multiple_hash.push_back(range_hash);
      }
      return multiple_hash;
		}
};
signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string text = "cu cu cu vai tomar no cu cu cu"; // :D
  string pat = "cu"; // ;D
  Hash h1(text, 2), h2(pat, 2); // double hashing
  vector<int> hash_pat = h2.get_hash(0, sz(pat) - 1);
  for(int i = 0, j = sz(pat) - 1; j < sz(text); i++, j++) {
    if(h1.get_hash(i, j) == hash_pat) {
      out("found string ->", text.substr(i, sz(pat)), "<- in (", i, j, ")");
    }
  }
}
