# PSEUDOCODE

"""
funtion prim(G, c):
  P = {1}; S = {}; M = V - {1}
  K[1] = 0
  T = {} // minimum spanning tree

  while P != {}:
      u = argmin{K[v] for v in P}
      P.remove(u)
      S.insert(u)

      if u != 1:
          T = T + {u, u.parent()}

      for v in u.neighbors():
          if v in P and c(u, v) < K(v):
              K(v) = c(u, v)
              p(v) = u

          if v in M:
              K(v) = c(u, v)
              p(v) = u
              M.remove(v)
              P.insert(v)
  return T
"""


def prim(G, c):
    P, S, M = {0}, set(), G.vertices - {0}
    K = [float("inf") for _ in G.vertices]
    p = [-1 for _ in G.vertices]
    K[0] = 0
    T = set()  # the minimum spanning tree (set of edges)

    while len(P) != 0:
        u, _ = min([(v, K[v]) for v in P])

        P.remove(u)
        S.add(u)

        if u != 0:
            T.add((u, p[u]))

        for v in G.neighbors(u):
            if v in P and c(u, v) < K[v]:
                K[v] = c(u, v)
                p[v] = u

            if v in M:
                K[v] = c(u, v)
                p[v] = u
                M.remove(v)
                P.add(v)
