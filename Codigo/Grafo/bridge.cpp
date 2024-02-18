int TIMER, n;
vector<int> pre(n), low(n), vis(n);
vector<vector<int>> g(n);
vector<pair<int, int>> bridge;

void dfs(int u, int p, int r) {
  vis[u] = 1;
  pre[u] = low[u] = TIMER++;
  for(auto nxt : g[u]) {
    if(!vis[nxt]) {
      dfs(nxt, u, r);
      low[u] = min(low[u], low[nxt]);
    } else {
      if(nxt != p) {
        low[u] = min(low[u], pre[nxt]);
      }
    }
  }
  if(u != r && low[u] == pre[u]) {
    bridge.emplace_back(u, p);
  }
}

vector<pair<int, int>> find_all_bridges() {
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      TIMER = 0;
      dfs(i, i, i);
    }
  }
  return bridge;
}
