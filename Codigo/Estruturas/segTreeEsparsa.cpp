// SegTree Esparsa
//
// Query: soma do range [i, j]
// Update: soma x em i
// O MAX tem q ser Q log N(quantos updates vai ter) para Q updates
// Contrutor: a(menor index que vou mudar), b(maior index que vou mudar)
//
// Complexidades:
// build - O(1)
// query - O(log(n))
// update - O(log(n))

template<typename T> struct dynamic_seg {
  int t;
  T neutral, a, b;
  T seg[MAX], esq[MAX], dir[MAX];
  function<T(T, T)> merge;
 
  dynamic_seg(T _a, T _b, T _neutral, function<T(T, T)> f) : a(_a), b(_b), neutral(_neutral), merge(f) {
    seg[0] = seg[1] = neutral;
    esq[0] = dir[0] = esq[1] = dir[1] = 0;
    t = 2;
  }
 
  int create() {
    seg[t] = neutral;
    esq[t] = dir[t] = 0;
    return t++;
  }
 
  T update(T i, T x, int p, T l, T r) {
    if(i < l or i > r) {
      return seg[p];
    }
    if(l == r) {//
      return seg[p] += x;
    }
    int mid = (l + r) >> 1; // tem que ser assim quando o range é negativo
    if(i <= mid) {
      if(esq[p] == 0) {
        esq[p] = create();
      }
    } else {
      if(dir[p] == 0) {
        dir[p] = create();
      }
    }
    return seg[p] = merge(update(i, x, esq[p], l, mid), update(i, x, dir[p], mid + 1, r));
  }
 
  T query(T i, T j, int p, T l, T r) {
    if(p == 0 or r < i or l > j) {
      return neutral;
    }
    if(l >= i && r <= j) {
      return seg[p];
    }
    int mid = (l + r) >> 1;
    return merge(query(i, j, esq[p], l, mid), query(i, j, dir[p], mid + 1, r));
  }
  
  T update(T i, T x) { return update(i, x, 1, a, b); }
  T query(T i, T j) { return query(i, j, 1, a, b); }
};


// Multi SegTree Esparsa
//
// Query: max no range [i, j]
// Update: muda o valor de i para x
// Contrutor: se tiver argumento -> a(menor index que vou mudar), b(maior index que vou mudar)
// Contrutor: se nao arrumar as funcoes e limites
//
// Complexidades:
// build - O(1)
// query - O(log(n))
// update - O(log(n))
 
template<typename T> struct dynamic_seg {
  int t;
  T neutral, a, b;
  vector<T> seg, esq, dir;
  function<T(T, T)> merge;
  
  dynamic_seg() {
    neutral = 0;
    a = -1, b = 1e9;
    merge = [&](T x, T y) {
      return max(x, y);
    };
    seg.emplace_back(neutral);
    seg.emplace_back(neutral);
    esq.emplace_back(0);
    esq.emplace_back(0);
    dir.emplace_back(0);
    dir.emplace_back(0);
    t = 2;
  }
 
  dynamic_seg(T _a, T _b, T _neutral, function<T(T, T)> f) : a(_a), b(_b), neutral(_neutral), merge(f) {
    seg.emplace_back(neutral);
    seg.emplace_back(neutral);
    esq.emplace_back(0);
    esq.emplace_back(0);
    dir.emplace_back(0);
    dir.emplace_back(0);
    t = 2;
  }
 
  int create() {
    seg.emplace_back(neutral);
    esq.emplace_back(0);
    dir.emplace_back(0);
    return t++;
  }
 
  T update(T i, T x, int p, T l, T r) {
    if(i < l or i > r) {
      return seg[p];
    }
    if(l == r) {//
      return seg[p] = x;
    }
    int mid = (l + r) >> 1; // tem que ser assim quando o range é negativo
    if(i <= mid) {
      if(esq[p] == 0) {
        esq[p] = create();
      }
    } else {
      if(dir[p] == 0) {
        dir[p] = create();
      }
    }
    return seg[p] = merge(update(i, x, esq[p], l, mid), update(i, x, dir[p], mid + 1, r));
  }
 
  T query(T i, T j, int p, T l, T r) {
    if(p == 0 or r < i or l > j) {
      return neutral;
    }
    if(l >= i && r <= j) {
      return seg[p];
    }
    int mid = (l + r) >> 1;
    return merge(query(i, j, esq[p], l, mid), query(i, j, dir[p], mid + 1, r));
  }
  
  T update(T i, T x) { return update(i, x, 1, a, b); }
  T query(T i, T j) { return query(i, j, 1, a, b); }
};
 
