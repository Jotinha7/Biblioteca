#include <bits/stdc++.h>
#define int long long
#define IOS ios_base::sync_with_stdio(false);cin.tie(0);
#define pb push_back
#define ms(v,x) memset(v,x,sizeof(v))
#define all(v) v.begin(),v.end()
#define f first
#define s second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = a; i >= b ; i--)
#define each(a, x) for (auto &a : x)
#define Unique(v) sort(all(v));v.erase(unique(all(v)),v.end());
#define sz(v) ((int)v.size())
#define bg(x) begin(x)
#define nd(x) end(x)
#define rall(x) x.rbegin(), x.rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define tos to_string
#define ft front()
#define bk back()
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef double db;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef pair<ll,ll> pll;
typedef pair<db, db> pdd;
typedef vector<ll> vl;
typedef vector<pii> vii;
typedef vector<piii> viii;
std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());
std::mt19937_64 rng64((int) std::chrono::steady_clock::now().time_since_epoch().count());
 
ll cdiv(ll a, ll b) { return a / b + ((a ^ b) > 0 && a % b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a / b - ((a ^ b) < 0 && a % b); } // divide a by b rounded down
ll gcd(ll a, ll b) { return (b == 0LL ? a : gcd(b, a % b)); }

const int MAXN = 2e5 + 5;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T){ cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr<<"(" << #__VA_ARGS__<<"):" , dbg_out(__VA_ARGS__) , cerr << endl


void solve() {
  
}

int32_t main() {
  IOS;
  int tt = 1;
  cin >> tt;
  while(tt--) {
    solve();
  }
  return 0;
}
