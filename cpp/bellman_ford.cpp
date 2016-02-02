// You need to set V_SIZE, E_SIZE, E_MAX
// O(|V||E|)
struct edge { int from, to, cost; }
edge es[E_MAX];

vector<int> bellman_ford(int s) {
  const int inf = (int)1e9;
  vector<int> d(V_SIZE, inf);
  d[s] = 0;
  while (1) {
    bool update = false;
    for (int i = 0; i < E_SIZE; i++) {
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

// O(|V||E|)
bool find_negative_loop() {
  vector<int> d(V_SIZE, 0);
  for (int i = 0; i < V_SIZE; i++) {
    for (int j = 0; j < E_SIZE; j++) {
      edge e = es[j];
      if (d[e.to] > d[e.from] + e.cost) {
        d[e.to] = d[e.from] + e.cost;
        if (i == V_SIZE - 1) return true;
      }
    }
  }
  return false;
}
