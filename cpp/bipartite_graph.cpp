// G is adjacency matrix
// O(|V| + |E|)
bool bipart_dfs(const Graph<int> &G, vector<int> &color, int v, int c) {
  color[v] = c;
  for (int i = 0; i < G[v].size(); i++) {
    if (color[G[v][i]] == c) return false;
    if (color[G[v][i]] == 0 && !bipart_dfs(G, color, G[v][i], -c)) return false; 
  }
  return true;
}

bool is_bipartite(const vector<vector<int>> &G) {
  vector<int> color(G.size(), 0);
  for (int i = 0; i < G.size(); i++) {
    if (color[i] == 0) {
      if (!dfs(G, color, i, 1)) return false;
    }
  }
  return true;
}
