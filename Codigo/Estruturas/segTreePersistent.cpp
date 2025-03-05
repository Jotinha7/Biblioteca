// SegTree Persistente
//
// SegTree de soma, update de somar numa posicao
//
// 
// query(a, b, t) retorna a query de [a, b] na versao t
// primeiro update tem que chamar pra versao 0
// update(a, x, t) faz um update v[a]+=x a partir da
// versao de t, criando uma nova versao e retornando seu id 
//
// n = (MAX - MIN)
// query - O(log(n))
// update - O(log(n))

const int lg = 32, maxn = 100005;

namespace perseg {

  vector<int> seg, esq, dir;
 
  void build() {
    seg.reserve(lg * maxn);
    esq.reserve(lg * maxn);
    dir.reserve(lg * maxn);
    seg.emplace_back(0); // tem que ser o elemento neutro da operacao aqui
    esq.emplace_back(0);
    dir.emplace_back(0);
  }

  int merge(int a, int b) {
    return a + b;
  }
 
  int create() {
    seg.emplace_back(0);
    esq.emplace_back(0);
    dir.emplace_back(0);
    return (int) seg.size() - 1;
  }
 
  int update(int i, int x, int t, int l, int r) {
    int u = create();
    seg[u] = seg[t];
    dir[u] = dir[t];
    esq[u] = esq[t];
    if(l == r) {
      seg[u] += x;
      return u;
    }
    int mid = (l + r) >> 1;
    if(i <= mid) {
      esq[u] = update(i, x, esq[t], l, mid);
    } else {
      dir[u] = update(i, x, dir[t], mid + 1, r);
    }
    seg[u] = merge(seg[esq[u]], seg[dir[u]]);
    return u;
  }
 
  int query(int i, int j, int t, int l, int r) {
    if(l > j or r < i) {
      return 0;
    }
    if(l >= i && r <= j) {
      return seg[t];
    }
    int mid = (l + r) >> 1;
    return query(i, j, esq[t], l, mid) + query(i, j, dir[t], mid + 1, r);
  }

};
