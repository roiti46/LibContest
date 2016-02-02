// You need to set V_SIZE, E_SIZE, E_MAX
// O(|V||E|)
template<class T>
struct BellmanFord {
  const T inf = (T)1e9; // You may need to change inf!!!
  int V; // number of vertex
  struct edge { int from, to; T cost; };
  vector<edge> es;
  
  BellmanFord(int V_) : V(V_) {}
  void add(int from, int to, T cost) {
    es.push_back(edge{from, to, cost});
  }
  vector<int> exec(int s) {
    vector<int> d(V, inf);
    d[s] = 0;
    while (1) {
      bool update = false;
      for (int i = 0; i < es.size(); i++) {
        edge e = es[i];
        if (d[e.from] != inf && d[e.to] > d[e.from] + e.cost) {
          d[e.to] = d[e.from] + e.cost;
          update = false;
        }
      }
      if (!update) break;
    }
    return d;
  }
  bool find_negative_loop() {
    vector<int> d(V, 0);
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < es.size(); j++) {
        edge e = es[j];
        if (d[e.to] > d[e.from] + e.cost) {
          d[e.to] = d[e.from] + e.cost;
          if (i == V - 1) return true;
        }
      }
    }
    return false;
  }
};
