namespace seg {
  vector<long long> seg, lazy;
  vector<int> a;
  int n;

  long long combina(int a, int b) {
    return a + b;
  }
  
  long long build(int p = 1, int l = 0, int r = n - 1) {
    lazy[p] = 0;
    if (l == r) {
      return seg[p] = a[l];
    }
    int m = (l + r) / 2;
    return seg[p] = combina(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
  }
  
  void build(int n2, vector<int>& v2) {
    n = n2, a = v2;
    seg = lazy = vector<long long> (4 * n);
    build();
  }
  
  void prop(int p, int l, int r) {
    if(lazy[p]) {
      seg[p] += (r - l + 1) * lazy[p];
      if (l != r) {
        lazy[2 * p] += lazy[p];
        lazy[2 * p + 1] += lazy[p];
      }
    }
    lazy[p] = 0;
  }
  
  long long query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
    prop(p, l, r);
    if (a <= l and r <= b) {
      return seg[p];
    }
    if (b < l or r < a) {
      return 0;
    }
    int m = (l + r) / 2;
    return combina(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
  }
  
  long long update(int a, int b, int x, int p = 1, int l = 0, int r = n - 1) {
    prop(p, l, r);
    if (a <= l and r <= b) {
      lazy[p] += x;
      prop(p, l, r);
      return seg[p];
    }
    if (b < l or r < a) {
      return seg[p];
    }
    int m = (l + r) / 2;
    return seg[p] = combina(update(a, b, x, 2 * p, l, m),
      update(a, b, x, 2 * p + 1, m + 1, r));
  }
};
