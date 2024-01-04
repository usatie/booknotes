#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1LL << 60;


int main() {
  int N, M;
  cin >> N >> M;

  // DP
  vector< vector<long long> > dp(N, vector<long long>(N, INF));

  // DP Initialization
  for ( int e = 0; e < M; e++ ) {
    int a, b;
    long long w;
    cin >> a >> b >> w;
    dp[a][b] = w;
  }
  for ( int v = 0; v < N; v++ ) dp[v][v] = 0;

  // Floyd-Warshall
  for (int k = 0; k < N; ++k) // Route via k
    for (int i = 0; i < N; ++i) 
      for (int j = 0; j < N; ++j) 
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);

  bool exist_negative_cycle = false;
  for (int v = 0; v < N; ++v) if (dp[v][v] < 0) exist_negative_cycle = true;
  if (exist_negative_cycle) {
    cout << "NEGATIVE CYCLE" << endl;
  } else {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j){
        if (j) cout << " ";
        if (dp[i][j] < INF/2) cout << dp[i][j];
        else cout << "INF";
      }
      cout << endl;
    }
  }
}

/* Input Example
$ ./a.out <<EOF
4 6
0 1 1
0 2 5
1 2 2
1 3 4
2 3 1
3 2 7
EOF
*/

/* Output Example
0 1 3 4
INF 0 2 3
INF INF 0 1
INF INF 7 0
*/
