from typing import Dict, List, Set, Tuple


class Graph:
    def __init__(
        self,
        vertices: Set[int] | None = None,
        edges: Set[Tuple[int, int]] | None = None,
    ):
        if vertices is not None:
            self.vertices = vertices
        else:
            self.vertices = set()

        if edges is not None:
            self.edges = edges
        else:
            self.edges = set()

        self.adj = [
            [(1 if (i, j) in self.edges else 0) for j in range(len(self.vertices))]
            for i in range(len(self.vertices))
        ]

        self.edge_list: Dict[int, List[int]] = dict()
        for v in self.vertices:
            self.edge_list[v] = []

        for v in self.vertices:
            for u in self.vertices:
                if v == u:
                    continue
                if (u, v) or (v, u) in self.edges:
                    self.edge_list[v].append(u)

    def neighbors(self, v):
        return self.edge_list[v]
