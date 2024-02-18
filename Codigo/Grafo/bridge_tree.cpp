int TIMER, CONT;
stack<int> pilha;
vector<int> pre(maxn), low(maxn), vis(maxn), comp(maxn), vis_aresta(maxn);
vector<vector<int>> vertices_comp(maxn);
vector<vector<pair<int, int>>> g(maxn); // {vertice, id da aresta}

void dfs(int u, int p, int r) {
  vis[u] = 1;
  pre[u] = low[u] = TIMER++;
  pilha.push(u);
  for(auto [nxt, idx] : g[u]) {
    if(vis_aresta[idx]) {
      continue;
    }
    vis_aresta[idx] = 1;
    if(!vis[nxt]) {
      dfs(nxt, u, r);
      low[u] = min(low[u], low[nxt]);
    } else {
      low[u] = min(low[u], pre[nxt]);
    }
  }
  if(low[u] == pre[u]) {
    int v;
    do {
      v = pilha.top();
      pilha.pop();
      comp[v] = CONT;
      vertices_comp[CONT].push_back(v);
    } while(v != u);
    CONT++;
  }
}

vector<vector<int>> bridge_tree(int n) {
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      TIMER = 0;
      dfs(i, i, i);
    }
  }
  vector<vector<int>> tr(n);
  for(int i = 0; i < n; i++) {
    for(auto [nxt, idx] : g[i]) {
      if(comp[i] != comp[nxt]) {
        tr[comp[i]].push_back(comp[nxt]);
      }
    }
  }
  return tr;
}
