# -*- coding: utf-8 -*-
"""
隣接行列に対するダイクストラ法
O(V^2)
"""
def dijkstra(G, s):
    V = len(G)
    used = [False] * V
    d = [float("inf")] * V
    d[s] = 0
    while 1:
        v = -1
        for u in xrange(V):
            if not used[u] and (v == -1 or d[u] < d[v]):
                v = u

        if v == u: break

        for u in xrange(V):
            d[u] = min(d[u], d[v] + G[v][u])

    return d



"""
隣接リストに治するダイクストラ法
O(VlogE)
"""
import heapq
from collections import namedtuple

edge = namedtuple("edge","to cost")

def dijkstra(G, s):
    que = [[0, s]]
    d = [float("inf")] * len(G)
    d[s] = 0
    while que:
        c, v = heapq.heappop(que)
        if d[v] > c: continue
        for e in G[v]:
            if d[e.to] > d[v] + e.cost:
                d[e.to] = d[v] + e.cost
                heapq.heappush(que, [d[e.to], e.to])

    return d
