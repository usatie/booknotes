#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;

struct Edge {
  int to;
  long long w;
  Edge(int to, long long w) : to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template <class T> bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  // Vertices: N, Edges: M, Start: s
  int N, M, s;
  cin >> N >> M >> s;
  
  // Graph
  Graph G(N);
  for (int i = 0; i < M; ++i) {
    // a -> b (weight: w)
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back(Edge(b, w));
  }

  // Dijkstra
  vector<bool> used(N, false);
  vector<long long> dist(N, INF);
  dist[s] = 0;
  for (int iter = 0; iter < N; ++iter) {
    long long min_dist = INF;
    int min_v = -1;
    for (int v = 0; v < N; ++v) {
      if (used[v]) continue;
      if (dist[v] < min_dist) {
        min_dist = dist[v];
        min_v = -1;
      }
    }

    // If such 
    if (min_v == -1) break;

    // Relax
    for (auto e: G[min_v]) {
      chmin(dist[e.to], dist[min_v] + e.w);
    }
    used[min_v] = true;
  }

  // Output
  for (int v = 0; v < N; ++v) {
    if (dist[v] < INF) cout << dist[v] << endl;
    else cout << "INF" << endl;
  }
}

/* Input Example
$ ./a.out <<EOF
4 5 0
0 1 1
0 2 4
1 2 2
2 3 1
1 3 5
EOF
*/

/* Output
0
1
3
4
*/
