const int mod = int(1e9) + 7;

using matrix = vector<vector<int64_t>>;

matrix mul(const matrix& a, const matrix& b) {
  int n = (int) a.size(), m = (int) a[0].size(), o = (int) b[0].size();
  matrix c(n, vector<int64_t> (o));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < o; j++) {
      for(int k = 0; k < m; k++) {
        c[i][j] += (a[i][k] * b[k][j]) % mod;
        c[i][j] %= mod;
      }
    }
  }
  return c;
};

matrix fpow(matrix x, int64_t p) {
  int n = (int) x.size();
  matrix id(n, vector<int64_t> (n));
  for(int i = 0; i < n; i++) {
    id[i][i] = 1;
  }
  for(; p > 0; p /= 2) {
    if(p % 2 == 1) {
      id = mul(id, x);
    }
    x = mul(x, x);
  }
  return id;
};
