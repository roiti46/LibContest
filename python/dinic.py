class MaxFlowDinic:
    class edge:
        def __init__(self, to, rev, cap):
            self.to, self.rev, self.cap = to, rev, cap

    def __init__(self, v):
        self.V = v
        self.G = [[] for i in xrange(self.V)]

    def add(self, frm, to, cap):
        self.G[frm].append(self.edge(to, len(self.G[to]), cap))
        self.G[to].append(self.edge(frm, len(self.G[frm]) - 1, 0))

    def add_dual(self, frm, to, cap):
        self.G[frm].append(self.edge(to, len(self.G[to]), cap))
        self.G[to].append(self.edge(frm, len(self.G[frm]) - 1, cap))

    def bfs(self, s):
        self.level = [-1] * self.V
        self.level[s] = 0
        que = []
        que.append(s)
        while (que):
            v = que.pop(0)
            for i in xrange(len(self.G[v])):
                e = self.G[v][i];
                if e.cap > 0 and self.level[e.to] < 0:
                    self.level[e.to] = self.level[v] + 1;
                    que.append(e.to)


    def dfs(self, v, t, f):
        if v == t: return f
        for i in xrange(self.itr[v], len(self.G[v])):
            self.itr[v] = i
            e = self.G[v][i]
            if e.cap > 0 and self.level[v] < self.level[e.to]:
                d = self.dfs(e.to, t, min(f, e.cap))
                if d > 0:
                    e.cap -= d
                    self.G[e.to][e.rev].cap += d
                    return d
        return 0

    def max_flow(self, s, t):
        inf = float("inf")
        flow = 0
        while 1:
            self.bfs(s)
            if self.level[t] < 0: return flow

            self.itr = [0] * self.V
            f = self.dfs(s, t, inf)
            while f > 0:
                flow += f
                f = self.dfs(s, t, inf)
