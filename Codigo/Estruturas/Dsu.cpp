class DSU {
  public:
    int n;
    vector<int> id, sz;

    DSU(int _n) : n(_n) {
      sz = vector<int> (n, 1);
      id = vector<int> (n);
      iota(id.begin(), id.end(), 0);
    }

    int find(int x) {
      return id[x] = (id[x] == x ? x : find(id[x]));
    }

    void uni(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(sz[x] > sz[y]) swap(x,y);
        id[x] = y;
        sz[y] += sz[x];
    }
};

//salva o vetor dos componentes

class DSU {
  public:
    int n;
    vector<int> id;
    vector<vector<int>> sz;

    DSU(int _n) : n(_n) {
      sz = vector<vector<int>> (n);
      for(int i = 0; i < n; i++) {
        sz[i].push_back(i);
      }
      id = vector<int> (n);
      iota(id.begin(), id.end(), 0);
    }
    
    int find(int x) {
      return id[x] = (id[x] == x ? x : find(id[x]));
    }

    void uni(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return;
        if(sz[x].size() > sz[y].size()) swap(x,y);
        id[x] = y;
        for(auto x : sz[x]) {
          sz[y].push_back(x);
        }
    }
};
