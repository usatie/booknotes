# 14章 グラフ(2)：最短路問題
## 14.1 最短路問題とは
## 14.2 最短路問題の整理
## 14.3 緩和
## 14.4 DAG上の最短路問題：動的計画法
- Directed Acyclic Graph
- Topological Sort -> DP
- Relaxations must be done in topological order.
- Topological Sort: O(V+E)
- DP (Relaxations): O(V + E)
- Total           : O(V + E)
## 14.5 単一始点最短路問題：ベルマン・フォード法
- Directed (Cyclic) Graph
- Relax all edges until no relaxation is possible.
- At most |V|-1 relaxations are needed.
- If |V| relaxations are done, there is a negative cycle.
## 14.6 単一始点最短路問題：ダイクストラ法
- Directed (Cyclic) Graph with non-negative weights
- S: set of vertices for which the shortest path is known

- 1. Find the vertex u not in S with the smallest distance from s.
- 2. Add u to S. (This is proved to be the shortest path.)
- 3. Relax all edges from u.
- 4. Repeat

- Relax all edges in order of distance from the source.
- Use a priority queue to find the next edge to relax.
## 14.7 全点対間最短路問題：フロイド・ワーシャル法
- Directed (Cyclic) Graph
- dp[k][i][j]: shortest path from i to j using vertices 0,1,...,k-1
- dp[k+1][i][j] = min(dp[k][i][j], dp[k][i][k] + dp[k][k][j])

## 14.8 参考：ポテンシャルと差分制約系
## 14.9 まとめ
