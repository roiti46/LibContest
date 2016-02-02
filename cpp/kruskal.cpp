// need UnionFind
// O(|E|log(|V|))

template<T>
struct Kruscal {
  int V;
  struct edge { int u, v; T cost; };
  vector<edge> es;

  Kruscal(int V_) : V(V_){};
  void add(int u, int v, T cost) {
    es.push_back(edge{u, v, cost});
  }
  bool edge_comp(const edge &e1, const edge &e2) {
    return e1.cost < e2.cost;
  }
  int exec() {
    sort(es, es + es.size(), edge_comp);
    UnionFind uf(V);
    T res = 0;
    for (int i = 0; i < es.size(); i++) {
      edge e = es[i];
      if (!uf.same(e.u, e.v)) {
        uf.unite(e.u, e.v);
        res += e.cost;
      }
    }
    return res;
  }
};
