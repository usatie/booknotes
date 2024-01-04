#include <iostream>
#include <vector>
using namespace std;
const long long INF = 1LL << 60; // 十分大きな値とする (ここでは 2^60)

int main() {
  // Input
  int N;
  cin >> N;
  vector<long long> h(N);
  for (int i = 0; i < N; ++i) cin >> h[i];

  // DP
  vector<long long> dp(N, INF);

  // Initial Condition
  dp[0] = 0;

  // Loop
  for (int i = 1; i < N; ++i) {
    if (i == 1) {
      dp[i] = abs(h[i] - h[i - 1]);
    } else {
      dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
  }

  // Answer
  cout << dp[N - 1] << endl;
}

/* 
 * Sample Input for this program
$ ./a.out <<EOF
6
30 10 60 10 60 50
EOF

 * Sample Output for this program
40
*/
