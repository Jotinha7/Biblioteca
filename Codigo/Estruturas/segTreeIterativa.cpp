// SegTree Iterativa
//
// Consultas 0-based
// Query: soma do range [a, b]
// Update: muda o valor da posicao p para o caso base
//
// Complexidades:
// build - O(n)
// query - O(log(n))
// update - O(log(n))

template<typename T> struct segtree {
  int n;
  T neutral;
  vector<T> t;
  function<T(T, T)> merge;

  segtree(vector<int> v, T _e, function<T(T, T)> f) : n((int) v.size()), merge(f), neutral(_e) {
    t = vector<T> (2 * n);
    for(int i = 0; i < n; i++) {
      t[i + n] = {v[i], 1};
    }
    for (int i = n - 1; i > 0; --i) {
      t[i] = merge(t[i << 1], t[(i << 1) | 1]);
    }
  }

  void update(int p, T value) {
    for (t[p += n] = value; p > 1; p >>= 1) {
      t[p >> 1] = merge(t[p], t[p ^ 1]);
    }
  }

  T query(int l, int r) {
    T res = neutral;
    for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
      if(l & 1) {
        res = merge(res, t[l++]);
      }
      if(r & 1) {
        res = merge(res, t[--r]);
      }
    }
    return res;
  }
};
