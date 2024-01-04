#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60; // 十分大きな値を用いる (ここでは 2^60)

struct Edge {
  int to;
  long long w;
  Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector< vector<Edge> >;

template<class T> bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  else return false;
}

int main() {
  // Vertices: N, Edges: M, Start: s
  int N, M, s;
  cin >> N >> M >> s;

  // Graph
  Graph G(N);
  for (int i = 0; i < M; ++i) {
    // from: a, to: b, weight: w
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back(Edge(b, w));
  }

  // Bellman-Ford
  bool exist_negative_cycle = false;
  vector<long long> dist(N, INF);
  dist[s] = 0;
  for (int iter = 0; iter < N; ++iter) {
    bool update = false;
    for (int v = 0; v < N; ++v) {
      if (dist[v] == INF) continue;
      for (auto e: G[v]) {
        update |= chmin(dist[e.to], dist[v] + e.w);
      }
    }
    // If no update, shortest paths are already found
    if (!update) break;

    // If update at N-th iteration, there is a negative cycle
    if (iter == N - 1 && update) exist_negative_cycle = true;
  }

  if (exist_negative_cycle) cout << "NEGATIVE CYCLE" << endl;
  else {
    for (int v = 0; v < N; ++v) {
      if (dist[v] < INF) cout << dist[v] << endl;
      else cout << "INF" << endl;
    }
  }
}

/* Input Example
$ ./a.out <<EOF
4 5 0
0 1 2
0 2 3
1 2 -5
1 3 1
2 3 2
EOF
*/
/* Output
0
2
-3
-1
*/
