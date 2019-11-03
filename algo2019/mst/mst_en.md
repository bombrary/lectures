# Minimum Spanning Tree

---

## What is Minimum Spanning Tree?

- Tree:
  A Graph which has no cycle.

---

- Spanning Tree:
  A subgraph which is tree and 
has all vertex.

---

- Minimum Spanning Tree:
  A spanning tree whose sum of weight is the least of others.

---

## Two kind of methods

- Prim's algorithm: Like dijkstra algorithm.
- Kraskal's algorithm: Using union find tree.

Kraskal's algorithm is easy to implement if there is union find tree.

---

## Kraskal's algorithm

- Greedy: choose edges with smaller weight.
- If cycle is made when the algorithm choose an edge, it is not accepted.

---

- $i$-th edge: vertex $(v,u)$
- Cycle is made when $i$-th edge chosen
  $\Leftrightarrow$
  Vertex $v$ and $u$ belong to a same connected component.
  - We come to use union find tree!

---

## Image

---

## Code
