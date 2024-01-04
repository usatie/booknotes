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
## 14.7 全点対間最短路問題：フロイド・ワーシャル法
## 14.8 参考：ポテンシャルと差分制約系
## 14.9 まとめ
