#include <bits/stdc++.h>
  
using namespace std;

#define int long long int

const int MAXN = 3 * 1e5 + 10;

int n, q;
vector<int> a(MAXN), seg(4 * MAXN);

int build(int p = 1, int l = 0, int r = n - 1) {
  if(l == r) return seg[p] = a[l];
  int mid = (l + r) / 2;
  return seg[p] = build(2 * p, l, mid) + build(2 * p + 1, mid + 1, r);
}

int query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
  if(l > b || r < a) return 0;
  if(l >= a && r <= b) return seg[p];

  int mid = (l + r) / 2;
  return query(a, b, 2 * p, l, mid) + query(a, b, 2 * p + 1, mid + 1, r);
}

int update(int i, int x, int p = 1, int l = 0, int r = n -1) {
  if(i < l || i > r) return seg[p];
  if(l == r) return seg[p] = x;

  int mid = (l + r) / 2;
  return seg[p] = update(i, x, 2 * p, l, mid) + update(i, x, 2 * p + 1, mid + 1, r);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  build(1, 0, n - 1);
  while(q--) {
    int op;
    cin >> op;
    if(op == 1) {
      int i, x;
      cin >> i >> x;
      update(i, x, 1, 0, n - 1);
    }
    else {
      int l, r;
      cin >> l >> r;
      r--;
      cout << query(l, r, 1, 0, n - 1) << '\n';
    }
  }
  return 0;
}
