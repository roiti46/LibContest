// dijkstra not work for graph has negative edge
// !set inf to suit for the cost_type
// O(|V|^2)
template<typename T>
vector<T> dijkstra(const Graph<T> &G, int s) {
  const T inf = (T)1e9;
  int V = G.size();
  vector<T> d(V, inf);
  vector<bool> used(V, false);
  // fill(prev, prev + V, -1);
  d[s] = 0;

  while (1) {
    int v = -1;
    for (int u = 0; u < V; u++) {
      if (!used[u] && (v == -1 || d[u] < d[v])) v = u;
    }
    if (v == -1) break;
    used[v] = true;

    for (int u = 0; u < V; u++) {
      d[u] = min(d[u], d[v] + G[v][u]);
      // prev[u] = v;
    }
  }
  return d;
}

// O(|E|log(|V|))
template<typename T>
struct edge { int to; T cost; };

template<class T>
vector<T> dijkstra(const Graph<edge<T>> &G, int s) {
  const T inf = (T)1e9;
  int V = G.size();
  typedef pair<T, int> P;
  priority_queue<P, vector<P>, greater<P>> que;
  vector<T> d(V, inf);
  // fill(prev, prev + V, -1);
  d[s] = 0;
  que.push(P(0, s));

  while (!que.empty()) {
    P p = que.top(); que.pop();
    int v = p.second;
    if (d[v] < p.first) continue;
    for (int i = 0; i < G[v].size(); i++) {
      edge<T> e = G[v][i];
      if (d[e.to] > d[v] + e.cost) {
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
        // prev[e.to] = v;
      }
    }
  }
  return d;
}

// get shortest path for vertex t
vector<int> get_shortest_path(int t) {
  vector<int> path;
  for (; t != -1; t = prev[t]) path.push_back(t);
  reverse(path.begin(), path.end());
  return path;
}
