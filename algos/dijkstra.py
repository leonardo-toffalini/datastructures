# PSEUDOCODE

# function dijkstra(G, s):
#     P = {s}; S = {}; M = V - {s}; K[s] = 0; p(s) = s
#     while P != {}:
#         u = argmin(K(v) for v in P)
#         P.remove(u)
#         S.insert(u)
#
#         for v in u.neighbors():
#             if v in P and K[u] + c(u, v) < K[v]:
#                 K[v] = K[u] + c(u, v)
#
#             if v in M:
#                 K[v] = K[u] + c(u, v)
#                 p(v) = u
#                 M.remove(v)
#                 P.insert(v)
