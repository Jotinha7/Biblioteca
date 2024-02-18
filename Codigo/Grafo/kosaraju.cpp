stack<int> ord;
vector<int> vis(maxn), comp(maxn);
vector<vector<int>> g(maxn), rg(maxn);

int dfs1(int u) {
  vis[u] = 1;
  for(auto nxt : g[u]) {
    if(!vis[nxt]) {
      dfs1(nxt);
    }
  }
  ord.push(u);
}

int dfs2(int u, int c) {
  vis[u] = 1;
  comp[u] = c;
  for(auto nxt : rg[u]) {
    if(!vis[nxt]) {
      dfs2(nxt, c);
    }
  }
}

vector<vector<int>> compress(int n) {
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      dfs1(i);
    }
  }
  for(int i = 0; i < n; i++) {
    vis[i] = 0;
  }
  int cnt = 0;
  while(!ord.empty()) {
    int u = ord.top(); ord.pop();
    if(!vis[u]) {
      dfs2(u, cnt);
      cnt += 1;
    }
  }
  vector<vector<int>> ng(cnt);
  for(int i = 0; i < n; i++) {
    for(auto nxt : g[i]) {
      if(comp[i] != comp[nxt]) {
        ng[comp[i]].push_back(comp[nxt]);
      }
    }
  }
  return ng;
}
