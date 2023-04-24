namespace ms_tree {
  vector<vector<int>> ms_tree(4 * MAXN);
  vector<int> a;
  int n;

  vector<int> combina(const vector<int>& x, const vector<int>& y) {
    vector<int> z((int) x.size() + (int) y.size());
    merge(x.begin(), x.end(), y.begin(), y.end(), z.begin());
    return z;
  }

  vector<int> build(int p = 1, int l = 0, int r = n - 1) {
    if (l == r) {
      return ms_tree[p] = {a[l]};
    }
    int m = (l+r)/2;
    return ms_tree[p] = combina(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
  }

  void build(int n2, vector<int>& v2) {
    n = n2, a = v2;
    build();
  }

  vector<int> query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
    if (a <= l and r <= b) return ms_tree[p];
    if (b < l or r < a) return {};
    int m = (l + r) / 2;
    return combina(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
  }
};
