struct Qry { int l, r, id; };

namespace mo {
  int n, m, cur, *a;
  vector<int> ans;
  Qry* q;
  vector<int> freq(int(1e6));

  /* add/remove an index and updates the current answer */
  void add(int x) {
    if(a[x] > n) return;
    if(++freq[a[x]] == a[x]) {
      cur++;
    }
    if(freq[a[x]] - 1 == a[x]) {
      cur--;
    }
  }
  void rem(int x) {
    if(a[x] > n) return;
    if(--freq[a[x]] == a[x]) {
      cur++;
    }
    if(freq[a[x]] + 1 == a[x]) {
      cur--;
    }
  }

  void mo() { // O(n * sqrt(n) * u), where u is the cost to add/remove an index
    int bs = (int)sqrt(n);
    sort(q, q + m, [bs](const Qry& x, const Qry& y) {
      int bx = x.l / bs, by = y.l / bs;
      if (bx != by) return bx < by;
      return bx % 2 == 0 ? x.r < y.r : x.r > y.r;
    });
    int mol = 0, mor = -1;
    for (int i = 0; i < m; ++i) {
      auto [l, r, id] = q[i];
      while (mor < r) add(++mor);
      while (mor > r) rem(mor--);
      while (mol < l) rem(mol++);
      while (mol > l) add(--mol);
      ans[id] = cur;  // answers the range [l, r] in O(1)
    }
  }

  void build(int _n, int _m, int* v2, Qry* q2) {
    n = _n, m = _m;
    ans.resize(m);
    a = v2, q = q2;
    mo();
  }
};
