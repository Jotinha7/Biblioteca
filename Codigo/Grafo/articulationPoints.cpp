int TIMER;
vector<int> pre(maxn), low(maxn), vis(maxn);
vector<vector<int>> g(maxn);
vector<int> res;

void dfs(int u, int p, int r) {
  vis[u] = 1;
  pre[u] = low[u] = TIMER++;
  bool articulation_point = false;
  int qtd_filho = 0;
  for(auto nxt : g[u]) {
    if(!vis[nxt]) {
      qtd_filho += 1;
      dfs(nxt, u, r);
      low[u] = min(low[u], low[nxt]);
      if(low[nxt] >= pre[u]) {
        articulation_point = true;
      }
    } else {
      if(nxt != p) {
        low[u] = min(low[u], pre[nxt]);
      }
    }
  }
  if(u == r && qtd_filho == 2) {
    res.push_back(u);
  }
  if(u != r && articulation_point) {
    res.push_back(u);
  } 
}

vector<int> find_all_articulation(int n) {
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      TIMER = 0;
      dfs(i, i, i);
    }
  }
  return res;
}
