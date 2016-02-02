struct SCC {
  vector<vector<int>> G, rG;
  vector<int> vs;
  vector<bool> used;
  vector<int> cmp; // topological order of scc groups

  SCC(int N) : G(N), rG(N), used(N), cmp(N) {}
  void clear_used() { fill(used.begin(), used.end(), false); }
  void add_edge(int from, int to) {
    G[from].push_back(to);
    rG[to].push_back(from);
  }
  void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < G[v].size(); i++) {
      if (!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
  }
  void rdfs(int v, int k) {
    used[v] = true;
    cmp[v] = k;
    for (int i = 0; i < rG[v].size(); i++) {
      if (!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
  }
  int decompose() {
    clear_used();
    vs.clear();
    for (int v = 0; v < G.size(); v++) {
      if (!used[v]) dfs(v);
    }
    fill(used.begin(), used.end(), false);
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) {
      if (!used[vs[i]]) rdfs(vs[i], k++);
    }
    return k;
  }
}
