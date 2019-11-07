#include <bits/stdc++.h>

using namespace std;

/**
  ワーシャルフロイド
  計算量O(n^3)
  全体全の最短距離を求める
 **/
#define NODE 301
long long dist[NODE][NODE];
void WF(int num){
  for(int k = 0;k < num;k++){
    for(int i = 0;i < num;i++){
      for(int j = 0;j < num;j++){
        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
      }
    }
  }
}

int main(){
  int H, W;
  int A[210][210];

  cin >> H >> W;
  for(int i = 0; i <= 9; i++) {
    for(int j = 0; j <= 9; j++) {
      cin >> dist[i][j];
    }
  }
  WF(10);

  int ans = 0;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      int A;
      cin >> A;
      if(A != -1) {
        ans += dist[A][1];
      }
    }
  }
  cout << ans << endl;

  return 0;
}
