// You need to set V_SIZE, E_SIZE, E_MAX
// Need UnionFind
// O(|E|log(|V|))
struct edge { int u, v, cost; };
edge es[E_MAX];

bool edge_comp(const edge &e1, const edge &e2) {
  return e1.cost < e2.cost;
}

int kruskal() {
  sort(es, es + E_SIZE, edge_comp);
  UnionFind uf(V_SIZE);
  int res = 0;
  for (int i = 0; i < E_SIZE; i++) {
    edge e = es[i];
    if (!uf.same(e.u, e.v)) {
      uf.unite(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}
