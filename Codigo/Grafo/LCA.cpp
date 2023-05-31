class LCA {
  public:
    int q_lca(int a, int b) {
      if(depth[a] > depth[b]) {
        swap(a, b);
      }
      for(int i = lg; i >= 0; i--) {
        if(depth[b] - (1 << i) >= depth[a]) {
          b = anc[b][i];
        }
      }
      if(a == b) {
        return a;
      }
      for(int i = lg; i >= 0; i--) {
        if(anc[a][i] != anc[b][i]) {
          a = anc[a][i];
          b = anc[b][i];
        }
      }
      return father[a];
    }
    LCA(int root, vector<vector<int>> graph) {
      n = (int) graph.size();
      lg = log2(n);
      depth = father = vector<int> (n);
      g = graph;
      anc = vector<vector<int>> (n, vector<int> (lg + 1));
      build(root);
    }
  private:
    int n, lg;
    vector<int> father, depth;
    vector<vector<int>> anc, g;
    void build(int root) {
      auto dfs = [&](auto self, int u, int p = -1, int nvl = 0) -> void {
        depth[u] = nvl;
        for(auto v : g[u]) {
          if(v != p) {
            anc[v][0] = father[v] = u;
            self(self, v, u, nvl + 1);
          }
        }
      };
      dfs(dfs, root);
      for(int i = 1; i <= lg; i++) {
          for(int v = 0; v < n; v++) {
          anc[v][i] = anc[anc[v][i - 1]][i - 1];
        }
      }
    }
};
