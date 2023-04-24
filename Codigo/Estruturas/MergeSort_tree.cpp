namespace ms_tree {
  vector<vector<long long>> ms_tree;
  vector<long long> a;
  int n;

  vector<long long> combina(const vector<long long>& x, const vector<long long>& y) {
    vector<long long> z((int) x.size() + (int) y.size());
    merge(x.begin(), x.end(), y.begin(), y.end(), z.begin());
    return z;
  }

  vector<long long> build(int p = 1, int l = 0, int r = n - 1) {
    if (l == r) {
      return ms_tree[p] = {a[l]};
    }
    int m = (l+r)/2;
    return ms_tree[p] = combina(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
  }

  void build(int n2, vector<long long>& v2) {
    n = n2, a = v2;
    ms_tree = vector<vector<long long>> (4 * n);
    build();
  }

  vector<long long> query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
    if (a <= l and r <= b) return ms_tree[p];
    if (b < l or r < a) return {};
    int m = (l + r) / 2;
    return combina(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
  }
};
