//cada ponto de articulacao é um no
//toda ponte é um no
//toda componente biconectada é um no
//cuidado com n == 1 ou quando nao tem ponto de articulacao
int TIMER, CONT;
stack<int> pilha;
vector<int> pre(maxn), low(maxn), vis(maxn), compEdge(maxn);
vector<int> vis_aresta(maxn), pontoDeArticulacao(maxn);
vector<vector<pair<int, int>>> g(maxn); // {vertice, id da aresta}

void novaCompBiconexa(int idEdge) {
  int a;
  if(pilha.empty()) {
    return;
  }
  do {
    a = pilha.top();
    pilha.pop();
    compEdge[a] = CONT;
    if(pilha.empty()) {
      break;
    }
  } while(a != idEdge);
  CONT++;
}

void dfs(int u, int r) {
  vis[u] = 1;
  pre[u] = low[u] = TIMER++;
  int qtdFilhos = 0;
  for(auto [nxt, idx] : g[u]) {
    if(vis_aresta[idx]) {
      continue;
    }
    pilha.push(idx);
    vis_aresta[idx] = 1;
    if(!vis[nxt]) {
      qtdFilhos += 1;
      dfs(nxt, r);
      low[u] = min(low[u], low[nxt]);
      bool novaComp = false;
      if(u == r && qtdFilhos >= 2) {
        novaComp = true;
      }
      if(u != r && low[nxt] >= pre[u]) {
        novaComp = true;
      }
      if(novaComp) {
        pontoDeArticulacao[u] = 1;
        novaCompBiconexa(idx);
      }
    } else {
      low[u] = min(low[u], pre[nxt]);
    }
  }
}

vector<vector<int>> blockCutTree(int n) {
  CONT = 0;
  for(int i = 0; i < n; i++) {
    if(!vis[i]) {
      TIMER = 0;
      dfs(i, i);
      novaCompBiconexa(-1);
    }
  }
  vector<int> visComp(CONT + n);
  vector<vector<int>> ng(CONT + accumulate(pontoDeArticulacao.begin(), pontoDeArticulacao.begin() + n, 0));
  for(int i = 0; i < n; i++) {
    if(pontoDeArticulacao[i] != 1) {
      continue;
    }
    pontoDeArticulacao[i] = CONT;
    CONT++;
    for(auto [nxt, id] : g[i]) {
      int comp = compEdge[id];
      if(visComp[comp] == 0) {
        visComp[comp] = 1;
        ng[pontoDeArticulacao[i]].push_back(comp);
        ng[comp].push_back(pontoDeArticulacao[i]);
      }
    }
    for(auto [nxt, id] : g[i]) {
      int comp = compEdge[id];
      visComp[comp] = 0;
    }
  }
  return ng;
}
