#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1LL << 60; // 十分大きな値

struct Edge {
  int to;
  int w;
  Edge(int to, int w) : to(to), w(w) {}
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
  int N, M, s;
  cin >> N >> M >> s;

  // Graph
  Graph G(N);
  for (int i = 0; i < M; ++i) {
    int a, b, w;
    cin >> a >> b >> w;
    G[a].push_back(Edge(b, w));
  }

  // Dijkstra with Heap
  vector<long long> dist(N, INF);
  dist[s] = 0;

  priority_queue< pair<long long, int>, // (d[v], v)
                  vector< pair<long long, int> >,
                  greater< pair<long long, int> > > que;
  que.push(make_pair(dist[s], s));
  while (!que.empty()) {
    // v : shortest length vertices
    // d : key (can be deprecated)
    long long d = que.top().first;
    int v = que.top().second;
    que.pop();

    // Deprecated
    if (dist[v] < d) continue;

    // Relax
    for (auto e: G[v]) {
      if (chmin(dist[e.to], dist[v] + e.w)) {
        que.push(make_pair(d + e.w, e.to));
      }
    }
  }

  for (int v = 0; v < N; ++v) {
    if (dist[v] < INF) cout << dist[v] << endl;
    else cout << "INF" << endl;
  }
}

/* Input Example
$ ./a.out <<EOF
7 9 0
0 1 2
0 2 5
1 2 4
2 3 2
1 3 6
1 4 10
3 5 1
4 5 3
4 6 5
EOF
*/

/* Output Example
0
2
5
7
12
8
17
*/
